#ifndef MECANUMDRIVESUBSYSTEM_H
#define MECANUMDRIVESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author Matthew
 */
class MecanumDriveSubsystem: public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	MecanumDriveSubsystem();
	void InitDefaultCommand();
};

#endif
