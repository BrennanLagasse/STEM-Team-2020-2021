#include <Servo.h>

// Make servos
Servo leftServo;
Servo rightServo;

const int leftEncoderPin1 = 2;
const int leftEncoderPin2 = 3;
const int rightEncoderPin1 = 4;
const int rightEncoderPin2 = 5;
const int leftInputPin1 = 6;
const int leftInputPin2 = 7;
const int leftEnablePin = 8;
const int rightInputPin1 = 9;
const int rightInputPin2 = 10;
const int rightEnablePin = 11;
const int leftServoPin = 12;
const int rightServoPin = 13;

// variable to store the servo position
int leftServoPos = 0;
int rightServoPos = 0;

void setup() {
  // Attach servos to pins 12 and 13
  leftServo.attach(leftServoPin);
  rightServo.attach(rightServoPin);
  
  // Encoder Pins
  pinMode(leftEncoderPin1, OUTPUT);
  pinMode(leftEncoderPin2, OUTPUT);
  pinMode(rightEncoderPin1, OUTPUT);
  pinMode(rightEncoderPin2, OUTPUT);
  
  // Motor Control Pins
  
}

void loop() {
  for (leftServoPos = 0; leftServoPos <= 180; leftServoPos += 1) {
    // in steps of 1 degree
    leftServo.write(leftServoPos);
    delay(15);
  }
  for (leftServoPos = 180; leftServoPos >=0; leftServoPos -= 1) {
    // in steps of 1 degree
    leftServo.write(leftServoPos);
    delay(15);
  }
  for (rightServoPos = 0; rightServoPos <= 180; rightServoPos += 1) {
    // in steps of 1 degree
    rightServo.write(rightServoPos);
    delay(15);
  }
  for (rightServoPos = 180; rightServoPos >=0; rightServoPos -= 1) {
    // in steps of 1 degree
    rightServo.write(rightServoPos);
    delay(15);
  }
}
