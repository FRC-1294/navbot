#ifndef MECANUMDRIVEBASECOMMAND_H
#define MECANUMDRIVEBASECOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class MecanumDriveBaseCommand: public CommandBase
{
private:
	//RobotDrive* d;
	CANJaguar *frontLeft, *rearLeft, *frontRight, *rearRight;
public:
	MecanumDriveBaseCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
