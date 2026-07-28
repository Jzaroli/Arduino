#include <Stepper.h>

// Number of steps per full revolution in 4-step mode
const int stepsPerRevolution = 2048; 

// Steps required for a 60-degree rotation (2048 * 60 / 360 = 341.33)
const int stepsFor60Degrees = 341;

// Initialize the library with correct pin mapping (8, 10, 9, 11) for ULN2003
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Set the motor speed to 15 RPM
  myStepper.setSpeed(15);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Rotate 60 degrees clockwise
  myStepper.step(stepsFor60Degrees);

  // Pause for 2 seconds
  delay(2000);
}
