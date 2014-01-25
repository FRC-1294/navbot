#include "OI.h"

/*
 * A little explanation about the beast that follows.
 * First, we define a map function that maps a value x from the range (a,b)->(c,d).
 * Roughly based off of this function: http://www.arduino.cc/en/Reference/Map
 * 
 * Next, we define a deadzone function.  If we are inside the deadzone, return zero.
 * If we are outside the deadzone (active) return a value mapped to the
 * output range (0,1) from the deadzoned input range (deadzone, 1). Maps (dz,1)->(0,1).
 */
#if JOYSTICK_DEADZONE_ENABLE
	#define JDZ JOYSTICK_DEADZONE
	#undef MAP
	#define MAP(x,inl,inh,outl,outh) ((x-inl)*(outh-outl)/(inh-inl)+outh)
	#define DZ(x) (x > 0 ?							\
					(x > JDZ ?						\
							MAP(x,JDZ,1,0,1)		\
							: 0)					\
					: (x < -JDZ ?					\
							MAP(x,JDZ,1,0,1)		\
							: 0))					
#else
#define DZ(x) (x)
#endif


OI::OI()
{
	xbox = new Joystick(JOYSTICK_XBOX);
}

float OI::GetTranslateX()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)JOYSTICK_XBOX_AXIS_X));
}

float OI::GetTranslateY()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)JOYSTICK_XBOX_AXIS_Y));
}

float OI::GetRotate()
{
	return DZ(this->xbox->GetAxis((Joystick::AxisType)JOYSTICK_XBOX_AXIS_ROT));
}

void OI::PrintInputs()
{
	printf("%3.3f\t%3.3f\t%3.3f\n", GetTranslateX(), GetTranslateY(),
			GetRotate());
}

#undef MAP
