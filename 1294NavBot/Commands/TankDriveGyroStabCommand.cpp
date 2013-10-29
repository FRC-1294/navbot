#include "TankDriveGyroStabCommand.h"
#include "../RobotMap.h"

TankDriveGyroStabCommand::TankDriveGyroStabCommand()
{
	Requires(drive);
}

// Called just before this Command runs the first time
void TankDriveGyroStabCommand::Initialize()
{
	drive->TankDrive(0, 0);

	if (pid)
	{
		delete pid;
		pid = 0;
	}

	pid = new PIDController(0, 0, 0, this, this, 0.05);
	pid->SetSetpoint(0);
	pid->SetOutputRange(-1, 1);
	pid->Enable();
}

// Called repeatedly when this Command is scheduled to run
void TankDriveGyroStabCommand::Execute()
{
	float p = 1.0;
	float i = 0;
	float d = 0;
	pid->SetPID(p, i, d);
	
	float l = oi->GetLeftY();
	float r = oi->GetRightY();

	y = (l + r) / 2; // Convert to "arcade" values
	float x = ((l - r) / 2) * GYRO_MAX_BOT_ROTATION_RATE;
	printf("X val: %3.3f\n", x);
	pid->SetSetpoint(x);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveGyroStabCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDriveGyroStabCommand::End()
{
	pid->Disable();
	drive->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveGyroStabCommand::Interrupted()
{
	drive->TankDrive(0, 0);
}

void TankDriveGyroStabCommand::PIDWrite(float x)
{
	float l = y + x;
	float r = y - x;
	
	drive->TankDrive(l, r);	
}

double TankDriveGyroStabCommand::PIDGet()
{
	return gyro->GetRate();
}
