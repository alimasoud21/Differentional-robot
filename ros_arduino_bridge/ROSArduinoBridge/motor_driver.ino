/***************************************************************
   Motor driver logic - Custom DIR/PWM Implementation
   *************************************************************/

#ifdef USE_BASE

#ifdef DIR_PWM_MOTOR_DRIVER

  void initMotorController() {
    // Initialize your specific PWM and DIR pins as outputs
    pinMode(RIGHT_MOTOR_PWM, OUTPUT);
    pinMode(RIGHT_MOTOR_DIR, OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(LEFT_MOTOR_DIR, OUTPUT);
  }
  
  void setMotorSpeed(int i, int spd) {
    unsigned char reverse = 0;
  
    // Handle reverse speeds
    if (spd < 0) {
      spd = -spd;
      reverse = 1;
    }
    
    // Cap the PWM signal at 255 (maximum analogWrite value)
    if (spd > 255) {
      spd = 255;
    }
    
    if (i == LEFT) { 
      // Set direction first, then write the PWM speed
      if (reverse == 0) { 
        digitalWrite(LEFT_MOTOR_DIR, HIGH); 
      } else { 
        digitalWrite(LEFT_MOTOR_DIR, LOW); 
      }
      analogWrite(LEFT_MOTOR_PWM, spd);
    }
    else { /* RIGHT */
      if (reverse == 0) { 
        digitalWrite(RIGHT_MOTOR_DIR, HIGH); 
      } else { 
        digitalWrite(RIGHT_MOTOR_DIR, LOW); 
      }
      analogWrite(RIGHT_MOTOR_PWM, spd);
    }
  }
  
  void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    setMotorSpeed(LEFT, leftSpeed);
    setMotorSpeed(RIGHT, rightSpeed);
  }

#else
  #error A motor driver must be selected!
#endif

#endif