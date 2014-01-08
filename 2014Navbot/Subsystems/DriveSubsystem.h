#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class DriveSubsystem: public Subsystem
{
private:
	CANJaguar* jagFL, *jagFR, *jagRL, *jagRR;
	Encoder* encL, *encR;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	DriveSubsystem();
	void InitDefaultCommand();
	void TankDrive(float l, float r);
	double GetSpeedLeft();
	double GetSpeedRight();
	double GetPositionLeft();
	double GetPositionRight();
	void SetControlMode(CANJaguar::ControlMode ctrlMode);
	void SetCoastBrake(CANJaguar::NeutralMode cbMode);
};

#endif
