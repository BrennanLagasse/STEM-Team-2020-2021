//Analog Sensor Code

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

  //Delay Time'
  Serial.print("   potVal + 50: ");
  Serial.println(potVal+50);

  //Blink LED
  digitalWrite(9, HIGH);
  delay(potVal+100);
  digitalWrite(9,LOW);
  delay(potVal+100);

  
}
