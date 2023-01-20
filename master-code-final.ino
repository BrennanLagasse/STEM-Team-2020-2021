//Constants

//H-Bridge
const int controlPin1 = 3;
const int controlPin2 = 4;
const int enablePin = 9;

//Controller
const int button1 = 2;
const int button2 = 5;
const int xPin = 0;
const int yPin = 1;

//Laser
const int laser = 10;

//Variables

//Motor Vars
bool motorEnabled = false;
int motorSpeed = 0;

//Laser Vars
bool laserOn = false;

//Button Values
int button1Val;
int button1Last;
int button2Val;
int button2Last;

//Joystick Values
double x = 0;
double y = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(laser, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Collect inputs
  button1Val = digitalRead(button1);
  button2Val = digitalRead(button2);
  x = analogRead(xPin);
  y = analogRead(yPin);
 
  //Switch state everytime the button is pressed (with release)
  
  if(button1Val == 0 && button1Last == 1){
    motorEnabled = !motorEnabled;
  }
  if(button2Val == 0 && button2Last == 1){
    laserOn = !laserOn;
  }
  

  //Update buttonLast
  button1Last = button1Val;
  button2Last = button2Val;

  //Power and Direction
  if(x>525){
    motorSpeed = ((x-511.50)/511.50)*255;
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    
  }
  else if(x<=500){
    motorSpeed = -((x-511.50)/511.50)*255;
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  else{
    motorSpeed = 0;
  }

  //Run motor if enabled
  if(motorEnabled){
    analogWrite(enablePin, motorSpeed);
  }
  else{
    analogWrite(enablePin, 0);
  }

  //Laser on if enabled
  if(laserOn){
    digitalWrite(laser, HIGH);
  }
  else{
    digitalWrite(laser, LOW);
  }

  //Print Everything
    Serial.print("X: ");
    Serial.print(x);
    Serial.print(" Y: ");
    Serial.print(y);
    Serial.print(" Button: ");
    Serial.println(button1Val);
    Serial.print(" Speed: ");
    Serial.println(motorSpeed);
    delay(250);
}
