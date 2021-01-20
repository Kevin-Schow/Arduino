//header
int sensorValue; 
int sensorLow = 1023; 
int sensorHigh = 0;

const int ledPin = 13;

//setup
void setup(){ 
	pinMode(ledPin, OUTPUT); 
	digitalWrite(ledPin, HIGH);
  	Serial.begin(9600);
  
  	while(millis() < 5000) {
      sensorValue = analogRead(A0); 
		if (sensorValue > sensorHigh){  
			sensorHigh = sensorValue; 
		} //end if() 
		if (sensorValue < sensorLow) {  
			sensorLow = sensorValue; 
		} 
	}
  	digitalWrite(ledPin, LOW); //turn LED off 
} 
        
//loop        
void loop() { 
	sensorValue = analogRead(A0);
    int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);
	tone(8, pitch, 20);
    Serial.print("pitch: "); 
	Serial.println(pitch); 
	delay(10); 
} //end loop()

  
