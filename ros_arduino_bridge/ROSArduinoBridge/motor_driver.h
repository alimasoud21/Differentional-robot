/***************************************************************
   Motor driver function definitions - by James Nugen
   *************************************************************/

// Define a custom driver type flag
#define DIR_PWM_MOTOR_DRIVER

#ifdef DIR_PWM_MOTOR_DRIVER
  // Right Motor
  #define RIGHT_MOTOR_PWM 6   // EN pin
  #define RIGHT_MOTOR_DIR 24  // DIR pin
  
  // Left Motor
  #define LEFT_MOTOR_PWM 5    // EN pin
  #define LEFT_MOTOR_DIR 22   // DIR pin
#endif


void initMotorController();
void setMotorSpeed(int i, int spd);
void setMotorSpeeds(int leftSpeed, int rightSpeed);
