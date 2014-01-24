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

#define DRIVE_FRONT_LEFT 2
#define DRIVE_FRONT_RIGHT 3
#define DRIVE_REAR_LEFT 4
#define DRIVE_REAR_RIGHT 5

// *******************
//		  Gyro
// *******************

#define GYRO_ANALOG_CHANNEL 1
#define GYRO_MAX_BOT_ROTATION_RATE 215

// *******************
//		 Input
// *******************

#define JOYSTICK_XBOX 1

#define JOYSTICK_DEADZONE 0.2


#endif