#include "OI.h"

OI::OI()
{
	xbox = new Joystick(JOYSTICK_XBOX);
	
}

#define MAPN(x,inl,inh,outl,outh) ((x-inl)*(outh-outl)/(inh-inl)+outh)
#define DZ(x) (x>0 ? (x > JOYSTICK_DEADZONE ? MAPN(x,JOYSTICK_DEADZONE,1,0,1) : 0) : (x < -JOYSTICK_DEADZONE ? MAPN(x,JOYSTICK_DEADZONE,1,0,1) : 0))

float OI::GetTranslateX()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)0));
}

float OI::GetTranslateY()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)1));
}

float OI::GetRotate()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)2));
}

void OI::PrintInputs()
{
	printf("%3.3f\t%3.3f\t%3.3f\n", GetTranslateX(), GetTranslateY(), GetRotate());
}
