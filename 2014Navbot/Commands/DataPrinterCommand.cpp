#include "DataPrinterCommand.h"

DataPrinterCommand::DataPrinterCommand()
{
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
}

// Called just before this Command runs the first time
void DataPrinterCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DataPrinterCommand::Execute()
{
	//double l = drive->GetPositionLeft();
	//double r = drive->GetPositionRight();
	//double dl = drive->GetSpeedLeft();
	//double dr = drive->GetSpeedRight();
	
	//float a = gyro->GetAngle();
	//float da = gyro->GetRate();
	
	//printf("Data: L: %3.3f\tR: %3.3f\tdL: %3.3f\tdR: %3.3f\tA: %3.3f\tdA:%3.3f\n", l, r, dl, dr, a, da);
}

// Make this return true when this Command no longer needs to run execute()
bool DataPrinterCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DataPrinterCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DataPrinterCommand::Interrupted()
{
}
