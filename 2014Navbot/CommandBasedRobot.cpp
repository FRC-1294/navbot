#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DataPrinterCommand.h"
#include "Commands/TankDriveCommand.h"
#include "CommandBase.h"

class CommandBasedRobot: public IterativeRobot
{
private:
	TankDriveCommand* tankDrive;
	LiveWindow *lw;
	DataPrinterCommand* datacmd;

	GyroSubsystem* gs;
	
	virtual void RobotInit()
	{
		CommandBase::init();
		datacmd = new DataPrinterCommand();
		lw = LiveWindow::GetInstance();
		tankDrive = new TankDriveCommand();
		gs = new GyroSubsystem();
	}

	virtual void AutonomousInit()
	{
		datacmd->Start();
	}

	virtual void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//autonomousCommand->Cancel();
		datacmd->Start();
		tankDrive->Start();
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TestPeriodic()
	{
		float a = gs->GetAngle();
		float da = gs->GetRate();
		
		printf("A: %3.3f\tdA:%3.3f\n", a, da);
		
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot)
;

