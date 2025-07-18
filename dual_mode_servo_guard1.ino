#include <Servo.h>

Servo myServo;
int buttonPin = 11;
int buttonState = 0;

#define SIGNAL_PIN 7  // Ultrasonic Signal pin

void setup() {
  myServo.attach(9);
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(SIGNAL_PIN, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  long duration;
  float distance;

  // Ultrasonic Trigger pulse
  digitalWrite(SIGNAL_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SIGNAL_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SIGNAL_PIN, LOW);

  // Switch to input mode to read echo
  pinMode(SIGNAL_PIN, INPUT);
  duration = pulseIn(SIGNAL_PIN, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Set pin back to output for next trigger
  pinMode(SIGNAL_PIN, OUTPUT);

  // Read button state
  buttonState = digitalRead(buttonPin);

  if (distance <= 10) {
    // Near object detected, automatic mode: servo moves
    myServo.write(90);
  } 
  else {
    // No near object, manual mode by button
    if (buttonState == LOW) {  // Button pressed
      myServo.write(90);
    } else {
      myServo.write(0);
    }
  }

  delay(200);
}