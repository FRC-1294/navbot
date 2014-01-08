#ifndef TANKDRIVEGYROSTABCOMMAND_H
#define TANKDRIVEGYROSTABCOMMAND_H

#include "../CommandBase.h"

/**
 *
 *
 * @author Matthew
 */
class TankDriveGyroStabCommand: public CommandBase, public PIDSource, public PIDOutput
{
private:
	PIDController* pid;
	float y;
public:
	TankDriveGyroStabCommand();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	
	/**
	 * PIDOutput and PIDInput Implementation
	 */
	void PIDWrite(float output);
	virtual double PIDGet();
};

#endif
