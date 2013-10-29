#include "TankDriveCommand.h"

TankDriveCommand::TankDriveCommand()
{
	Requires(drive);
}

// Called just before this Command runs the first time
void TankDriveCommand::Initialize()
{
	drive->TankDrive(0, 0);
}

// Called repeatedly when this Command is scheduled to run
void TankDriveCommand::Execute()
{
	float l = oi->GetLeftY();
	float r = oi->GetRightY();

	drive->TankDrive(l, r);
}

// Make this return true when this Command no longer needs to run execute()
bool TankDriveCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TankDriveCommand::End()
{
	drive->TankDrive(0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDriveCommand::Interrupted()
{
	drive->TankDrive(0, 0);
}
