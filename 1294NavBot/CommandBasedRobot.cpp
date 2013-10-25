#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/DataPrinterCommand.h"
#include "CommandBase.h"

class CommandBasedRobot: public IterativeRobot
{
private:
	
	LiveWindow *lw;
	DataPrinterCommand* datacmd;

	virtual void RobotInit()
	{
		CommandBase::init();
		datacmd = new DataPrinterCommand();
		lw = LiveWindow::GetInstance();
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
	}

	virtual void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	virtual void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot)
;

