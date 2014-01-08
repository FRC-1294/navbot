#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// ********************
//	   Drive Motors
// ******************** 

#define MOTOR_MODE_QUAD 0
#define MOTOR_MODE_DUAL 1

#define MOTOR_MODE MOTOR_MODE_QUAD

#define DRIVE_FRONT_LEFT 2
#define DRIVE_FRONT_RIGHT 3
#define DRIVE_REAR_LEFT 4
#define DRIVE_REAR_RIGHT 5

#define FRONT_LEFT_FACTOR 1
#define FRONT_RIGHT_FACTOR 1
#define REAR_LEFT_FACTOR 1
#define REAR_LEFT_FACTOR 1

// *******************
//		Encoders
// *******************

#define ENABLE_ENCODERS 0
#define ENCODER_LEFT_A 0
#define ENCODER_LEFT_B 0
#define ENCODER_RIGHT_A 0
#define ENCODER_RIGHT_B 0
#define ENCODER_LEFT_COUNTS_PER_METER 1
#define ENCODER_RIGHT_COUNTS_PER_METER 1
#define ENCODER_ENCODE_MODE Encoder::k2X

// *******************
//		  Gyro
// *******************

#define GYRO_ANALOG_CHANNEL 1
#define GYRO_MAX_BOT_ROTATION_RATE 180

// *******************
//		 Input
// *******************

#define JOYSTICK_LEFT 1
#define JOYSTICK_RIGHT 2

#endif
