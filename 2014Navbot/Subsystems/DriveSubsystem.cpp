#include "DriveSubsystem.h"
#include "../Robotmap.h"

DriveSubsystem::DriveSubsystem() :
	Subsystem("DriveSubsystem")
{
	this->jagFL = new CANJaguar(DRIVE_FRONT_LEFT);
	this->jagFR = new CANJaguar(DRIVE_FRONT_RIGHT);
#if MOTOR_MODE == MOTOR_MODE_QUAD
	this->jagRL = new CANJaguar(DRIVE_REAR_LEFT);
	this->jagRR = new CANJaguar(DRIVE_REAR_RIGHT);
#endif
#if ENABLE_ENCODERS
	this->encL = new Encoder((UINT32) ENCODER_LEFT_A, ENCODER_LEFT_B, false,
			ENCODER_ENCODE_MODE); // UINT32 cast hack to appease the compiler, prevent ambiguous call error.

	this->encR = new Encoder((UINT32) ENCODER_RIGHT_A, ENCODER_RIGHT_B, false,
			ENCODER_ENCODE_MODE);

	this->encL->SetDistancePerPulse(ENCODER_LEFT_COUNTS_PER_METER);
	this->encR->SetDistancePerPulse(ENCODER_RIGHT_COUNTS_PER_METER);
#endif
}

void DriveSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void DriveSubsystem::SetControlMode(CANJaguar::ControlMode c)
{
	this->jagFL->ChangeControlMode(c);
	this->jagFR->ChangeControlMode(c);
	this->jagRL->ChangeControlMode(c);
	this->jagRR->ChangeControlMode(c);
}

void DriveSubsystem::TankDrive(float l, float r)
{
	this->jagFL->Set(l);
	this->jagFR->Set(r);
	this->jagRL->Set(l);
	this->jagRR->Set(r);
}

double DriveSubsystem::GetSpeedLeft()
{
#if ENABLE_ENCODERS
	return this->encL->GetRate();
#else
	return 0;
#endif
}

double DriveSubsystem::GetSpeedRight()
{
#if ENABLE_ENCODERS
	return this->encR->GetRate();
#else
	return 0;
#endif
}

double DriveSubsystem::GetPositionLeft()
{
#if ENABLE_ENCODERS
	return this->encL->GetDistance();
#else
	return 0;
#endif
}

double DriveSubsystem::GetPositionRight()
{
#if ENABLE_ENCODERS
	return this->encR->GetDistance();
#else
	return 0;
#endif
}
