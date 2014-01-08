#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick *joyLeft, *joyRight;
public:
	OI();
	float GetLeftY();
	float GetRightY();
};

#endif
