// Sensor: HC-SR04 https://cdn.sparkfun.com/datasheets/Sensors/Proximity/HCSR04.pdf

const int trig_pin = 9;
const int echo_pin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
  delay(50);
}

void loop() {
  // Send 10 microsecond pulse to trig
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // waits for high signal from input_pin / echo_pin for 25000µs, which covers an echo distance of up to 4m or 23,500µs
  // note: speed of sound = ~343 m/s  or 0.0343 cm/µs
  // duration is the time it takes for the pulse to go there and back, hence why it's divided by 2 below
  unsigned long duration = pulseIn(echo_pin, HIGH, 30000UL);

  // distance = ( pulse_duration × speed_of_sound ) / 2
  float distance_cm = (duration * 0.0343) / 2;
  
  if (distance_cm < 0) {
    distance_cm = 0;
  } 

  // used in serial plotter
  Serial.println(distance_cm);

  // every 1s
  delay(1000);
}
