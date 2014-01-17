#include "CommandBase.h"
#include "Commands/Scheduler.h"

CommandBase::CommandBase(const char *name) :
	Command(name)
{
}

CommandBase::CommandBase() :
	Command()
{
}

// Initialize a single static instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DriveSubsystem* CommandBase::drive = NULL;
GyroSubsystem* CommandBase::gyro = NULL;

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drive = new DriveSubsystem();
	//gyro = new GyroSubsystem();

	oi = new OI();
}
