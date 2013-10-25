#ifndef ROBOTMAP_H
#define ROBOTMAP_H

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

#define DRIVE_FRONT_LEFT 2
#define DRIVE_FRONT_RIGHT 3
#define DRIVE_REAR_LEFT 4
#define DRIVE_REAR_RIGHT 5

#define ENCODER_LEFT_A 0
#define ENCODER_LEFT_B 0
#define ENCODER_RIGHT_A 0
#define ENCODER_RIGHT_B 0
#define ENCODER_LEFT_COUNTS_PER_METER 1
#define ENCODER_RIGHT_COUNTS_PER_METER 1
#define ENCODER_ENCODE_MODE Encoder::k2X

#define GYRO_ANALOG_CHANNEL 1

#endif
