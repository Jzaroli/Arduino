int led = 9;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  // pin 9 as the output for sketch
  pinMode(led, OUTPUT);
}

void loop() {
  // pin 9 to led  
  analogWrite(led, brightness);

  // changed fade amount on each loop
  brightness = brightness + fadeAmount;

  // reversese the direction of the fade at the end of its range
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  // 30 milliseconds
  delay(30);
}
