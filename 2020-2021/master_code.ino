#include <Servo.h>

// Make servos
Servo leftServo;
Servo rightServo;

// Digital

// DC Motors
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

//Servos
const int leftServoPin = 12;
const int rightServoPin = 13;

// Analog
const int extendPot = A0;
const int tipPot = A1;
const int cutPot = A2;

// variable to store the servo position
int servoPos = 0;

// Joystick info
double cutPos = 0;
double tipPos = 0;
double extendPos = 0;

void cut() {
  Serial.print("EMERGENCY CUT ACTIVATED");
  
  for (servoPos = 0; servoPos < 180; servoPos += 5) {
    leftServo.write(servoPos);
	rightServo.write(servoPos);
    delay(15);
  }
  
  delay(100);
  
  for (servoPos = 180; servoPos > 0; servoPos -= 5) {
    leftServo.write(servoPos);
	rightServo.write(servoPos);
    delay(15);
  }
  
  delay(100);
}

void extend(int power) {
}

void test() {
	Serial.println(":)");
}

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
  pinMode(leftEnablePin, OUTPUT);
  pinMode(rightEnablePin, OUTPUT);
  pinMode(leftInputPin1, OUTPUT);
  pinMode(leftInputPin2, OUTPUT);
  pinMode(rightInputPin1, OUTPUT);
  pinMode(rightInputPin2, OUTPUT);
  
  //Serial
  Serial.begin(9600);
  
  //Start motors at 0
  leftServo.write(0);
  rightServo.write(0);
  
  
}

void loop() {
  
  double cutPos = map(analogRead(cutPot), 0, 1023, 0, 100);
  double tipPos = map(analogRead(tipPot), 0, 1023, 0, 100);
  double extendPos = map(analogRead(extendPot), 0, 1023, 0, 100);
  
  
  /**
  //Run left servo and right servo at full power [0,255] in opposite directions
  
  digitalWrite(leftInputPin1, HIGH);
  digitalWrite(leftInputPin2, LOW);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(leftEnablePin, 200);
 
  // Turn on motor B
 
  digitalWrite(rightInputPin1, LOW);
  digitalWrite(rightInputPin2, HIGH);
 
  // Set speed to 200 out of possible range 0~255
 
  analogWrite(rightEnablePin, 200);
  */
  
  if(cutPos > 50) {
  	cut();
  }
  
  
  test();
  
  
  
  
  delay(200);

  
  
}
