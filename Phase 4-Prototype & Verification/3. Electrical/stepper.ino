/*
 * Copied from 2448 motor driver information for driving stepper motors
 */
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 4, 5, 6, 7);  // CORRESPONDING PINS ON DRIVER MODULE: AIN2, AIN1, BIN1, BIN2

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  Serial.println("Stepper test!");
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(60);
}

void loop() {
  Serial.println("Forward");
  stepper.step(STEPS);

  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH)
      delay(10);
    while (digitalRead(2) == LOW)
      delay (10);
  }

  Serial.println("Backward");
  stepper.step(-STEPS);
  
  if (digitalRead(2) == HIGH) {
    while (digitalRead(2) == HIGH)
      delay(10);
    while (digitalRead(2) == LOW)
      delay (10);
  }
}
