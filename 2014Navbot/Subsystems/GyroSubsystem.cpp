#include "GyroSubsystem.h"
#include "../Robotmap.h"

GyroSubsystem::GyroSubsystem() :
	Subsystem("GyroSubsystem")
{
	this->g = new Gyro(GYRO_ANALOG_CHANNEL);
}

void GyroSubsystem::InitDefaultCommand()
{

}

void GyroSubsystem::ResetAngle()
{
	g->Reset();
}

float GyroSubsystem::GetAngle()
{
	return g->GetAngle();
}

float GyroSubsystem::GetRate()
{
	double a = g->GetAngle();
	double dT = this->GetPeriod();
	double dA = a - lastA;
	lastA = a;
	return dA / dT;
}

inline double GyroSubsystem::GetPeriod()
{
	double t = GetTime();
	double dt = t - lastT;
	lastT = t;
	return dt;
}
