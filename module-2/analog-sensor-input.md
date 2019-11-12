/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  http://www.arduino.cc/starterKit

  This example code is part of the public domain.
*/

//analog pin used to connect the potentiometer
int const potPin = A0;

// variable to read the value from the analog pin
int potVal;

void setup() {
  //Define LED
  pinMode(9,OUTPUT);
  
  // open a serial connection to your computer
  Serial.begin(9600);
}

void loop() {
  // read the value of the potentiometer
  potVal = analogRead(potPin); 
  
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  //Blink LED
  digitalWrite(9, HIGH);
  delay(potVal+100);
  digitalWrite(9,LOW);
  delay(potVal+100);

  
}
