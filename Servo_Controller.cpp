//include library
#include <Servo.h>


//define variables and constants
Servo myServo;

int const potPin = A0; //analog pin A 
int potVal; //stores value of pot 
int angle = 0; //stores position of servo



//setup function
void setup() { 
  myServo.attach(9);
    Serial.begin(9600);  
}

//loop function
void loop() { 
  potVal = analogRead(potPin); 
  Serial.print("potVal: "); 
  Serial.print(potVal);
  
    angle = map(potVal, 0, 1023, 0, 179); //angle is the pot value re-scaled to 0-179 
  Serial.print(", angle: "); 
  Serial.println(angle);
  
    myServo.write(angle); 
  delay(15); 
}
  
