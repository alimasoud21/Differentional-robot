/* *************************************************************
   Encoder definitions - Adapted for Arduino MEGA
   ************************************************************ */
   
#ifdef USE_BASE

#ifdef ARDUINO_ENC_COUNTER
  volatile long left_enc_pos = 0L;
  volatile long right_enc_pos = 0L;

  /* Interrupt routine for LEFT encoder */
  void leftEncoderISR() {
    if (digitalRead(LEFT_ENC_PIN_A) == digitalRead(LEFT_ENC_PIN_B)) {
      left_enc_pos++;
    } else {
      left_enc_pos--;
    }
  }

  /* Interrupt routine for RIGHT encoder */
  void rightEncoderISR() {
    if (digitalRead(RIGHT_ENC_PIN_A) == digitalRead(RIGHT_ENC_PIN_B)) {
      right_enc_pos++;
    } else {
      right_enc_pos--;
    }
  }

  /* Initialization function to attach the hardware interrupts */
  void initEncoders() {
    pinMode(LEFT_ENC_PIN_A, INPUT_PULLUP);
    pinMode(LEFT_ENC_PIN_B, INPUT_PULLUP);
    pinMode(RIGHT_ENC_PIN_A, INPUT_PULLUP);
    pinMode(RIGHT_ENC_PIN_B, INPUT_PULLUP);

    // Attach interrupts to Pin A for both motors
    attachInterrupt(digitalPinToInterrupt(LEFT_ENC_PIN_A), leftEncoderISR, CHANGE);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ENC_PIN_A), rightEncoderISR, CHANGE);
  }

  /* Wrap the encoder reading function */
  long readEncoder(int i) {
    if (i == LEFT) return left_enc_pos;
    else return right_enc_pos;
  }

  /* Wrap the encoder reset function */
  void resetEncoder(int i) {
    if (i == LEFT){
      left_enc_pos = 0L;
    } else { 
      right_enc_pos = 0L;
    }
  }
#else
  #error A encoder driver must be selected!
#endif

/* Wrap the encoder reset function */
void resetEncoders() {
  resetEncoder(LEFT);
  resetEncoder(RIGHT);
}

#endif