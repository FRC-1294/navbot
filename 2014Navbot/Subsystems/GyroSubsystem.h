#ifndef GYROSUBSYSTEM_H
#define GYROSUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class GyroSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Gyro* g;
public:
	GyroSubsystem();
	void InitDefaultCommand();
	float GetAngle();
	float GetRate();
	void ResetAngle();
};

#endif
