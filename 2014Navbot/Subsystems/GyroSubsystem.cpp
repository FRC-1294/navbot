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
	return g->GetRate();
}
