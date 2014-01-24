#include "MecanumDriveBaseCommand.h"

MecanumDriveBaseCommand::MecanumDriveBaseCommand()
{
	Requires(mecanumDrive);

	d = new RobotDrive(
			new CANJaguar(DRIVE_FRONT_LEFT, CANJaguar::kPercentVbus),
			new CANJaguar(DRIVE_REAR_LEFT, CANJaguar::kPercentVbus),
			new CANJaguar(DRIVE_FRONT_RIGHT, CANJaguar::kPercentVbus),
			new CANJaguar(DRIVE_REAR_RIGHT, CANJaguar::kPercentVbus));
}

// Called just before this Command runs the first time
void MecanumDriveBaseCommand::Initialize()
{
	d->SetSafetyEnabled(false);
}

// Called repeatedly when this Command is scheduled to run
void MecanumDriveBaseCommand::Execute()
{
	d->MecanumDrive_Cartesian(oi->GetTranslateX(), oi->GetTranslateY(),
			oi->GetRotate(), 0);
}

// Make this return true when this Command no longer needs to run execute()
bool MecanumDriveBaseCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void MecanumDriveBaseCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MecanumDriveBaseCommand::Interrupted()
{
}
