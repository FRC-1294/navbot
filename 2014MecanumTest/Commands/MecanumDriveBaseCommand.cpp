#include "MecanumDriveBaseCommand.h"

#include "../Util/MecanumCalc.h"

MecanumDriveBaseCommand::MecanumDriveBaseCommand()
{
	Requires(mecanumDrive);

	frontLeft = new CANJaguar(DRIVE_FRONT_LEFT, CANJaguar::kPercentVbus);
	rearLeft = new CANJaguar(DRIVE_REAR_LEFT, CANJaguar::kPercentVbus);
	frontRight = new CANJaguar(DRIVE_FRONT_RIGHT, CANJaguar::kPercentVbus);
	rearRight = new CANJaguar(DRIVE_REAR_RIGHT, CANJaguar::kPercentVbus);
	
	frontLeft->SetSafetyEnabled(false);
	rearLeft->SetSafetyEnabled(false);
	frontRight->SetSafetyEnabled(false);
	rearRight->SetSafetyEnabled(false);

	//d = new RobotDrive(frontLeft, rearLeft, frontRight, rearRight);
}

// Called just before this Command runs the first time
void MecanumDriveBaseCommand::Initialize()
{
	//d->SetSafetyEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveBaseCommand::Execute()
{
	double x = oi->GetTranslateX();
	double y = oi->GetTranslateY();
	double r = oi->GetRotate();
	
	MechDriveResult* drv = MecanumCalc::ComputeMechanum(x, y, r, 0, 1.0);
	
	uint8_t syncGroup = 0x80;
	
	frontLeft->Set(drv->f_mech.FrontLeft, syncGroup);
	rearLeft->Set(drv->f_mech.RearLeft, syncGroup);
	frontRight->Set(drv->f_mech.FrontRight, syncGroup);
	rearRight->Set(drv->f_mech.RearRight, syncGroup);
	
	CANJaguar::UpdateSyncGroup(syncGroup);
	
	//d->MecanumDrive_Cartesian(oi->GetTranslateX(), oi->GetTranslateY(),
	//		oi->GetRotate(), 0);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveBaseCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumDriveBaseCommand::End()
{
	frontLeft->Set(0);
	rearLeft->Set(0);
	frontRight->Set(0);
	rearRight->Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveBaseCommand::Interrupted()
{
}
