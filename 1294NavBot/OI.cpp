#include "OI.h"
#include "Robotmap.h"

OI::OI()
{
	this->joyLeft = new Joystick(JOYSTICK_LEFT);
	this->joyRight = new Joystick(JOYSTICK_RIGHT);
}

float OI::GetLeftY()
{
	return -this->joyLeft->GetAxis(Joystick::kYAxis);
}

float OI::GetRightY()
{
	return -this->joyRight->GetAxis(Joystick::kYAxis);
}
