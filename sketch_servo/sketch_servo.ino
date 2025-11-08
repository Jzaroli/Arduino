// Servo used is SG90, http://www.ee.ic.ac.uk/pcheung/teaching/DE1_EE/stores/sg90_datasheet.pdf
// 5V (4.8V) and 180 degree total range.

// This program moves the servo through different angles and lights up the led at 45 and 135 degrees. 

#include <Servo.h>
Servo myservo;

int servo_pin = 9; // pin for servo
int led_pin = 8;

void setup() {
  myservo.attach(servo_pin);
  myservo.write(0); // starting angle
  pinMode(led_pin, OUTPUT);
}

void move_servo(int angle) {
  myservo.write(angle);
  if (angle == 45 || angle == 135) {
    analogWrite(led_pin, 150);
  } else {
    analogWrite(led_pin, 0);
  }
  delay(750);
}

void loop() {
  // iterates through 180 degrees in 45 degree increments every 750ms and lights up the LED
  move_servo(0);
  move_servo(45);
  move_servo(90);
  move_servo(135);
  move_servo(180);
}
