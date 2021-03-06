const int greenLEDPin = 9; 
const int blueLEDPin = 10; 
const int redLEDPin = 11;  
const int redSensorPin = A0; 
const int greenSensorPin = A1; 
const int blueSensorPin = A2;

int redValue = 0; 
int greenValue = 0; 
int blueValue = 0;  
int redSensorValue = 0; 
int greenSensorValue = 0; 
int blueSensorValue = 0;

void setup()
{
  	Serial.begin(9600); 
	pinMode(greenLEDPin, OUTPUT); 
	pinMode(redLEDPin, OUTPUT); 
	pinMode(blueLEDPin, OUTPUT); 
}

void loop()
{
  	redSensorValue = analogRead(redSensorPin); 
	delay(5); 
	greenSensorValue = analogRead(greenSensorPin); 
	delay(5); 
	blueSensorValue = analogRead(blueSensorPin);
  
  	Serial.print("Raw SensorValues \t Red: "); 
	Serial.print(redSensorValue); 
	Serial.print("\t Green: "); 
	Serial.print(greenSensorValue); 
	Serial.print("\t Blue: "); 
	Serial.println(blueSensorValue);
  
  //convert sensor values to PWM duty cycle # 
	redValue = redSensorValue/4; 
	blueValue = blueSensorValue/4; 
	greenValue = greenSensorValue/4;
  
  //report PWM values to serial port 
	Serial.print("Mapped SensorValues \t Red: "); 	
	Serial.print(redValue); 
	Serial.print("\t Blue: "); 
	Serial.print(blueValue); 
	Serial.print("\t Green: "); 
	Serial.println(greenValue);
  
  //change color of LED
	analogWrite(redLEDPin, redValue); 
	analogWrite(greenLEDPin, greenValue); 
	analogWrite(blueLEDPin, blueValue); 
}
