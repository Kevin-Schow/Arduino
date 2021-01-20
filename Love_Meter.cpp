//header
//define constants and variables

const int sensorPin = A0; 
const float baselineTemp = 20.0; //20 degrees celsius

//setup

void setup(){
  //open a serial port
  Serial.begin(9600);
  
  //start with pin 2. Add 1 and repeat the loop.
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }
}

//loop

void loop(){ 
  int sensorVal = analogRead(sensorPin);
    Serial.print("Sensor Value: "); 
  Serial.print(sensorVal);
  
    //convert the ADC reading to voltage 
  float voltage = (sensorVal/1024.0)*5.0;
  
  //print new value to serial monitor 
  Serial.print(", Volts: "); 
  Serial.print(voltage);
  
    //convert the voltage to temperature in degrees
  float temperature = (voltage - .5)*100; 
  Serial.print(", degrees C: "); 
  Serial.println(temperature);
  
    if(temperature < baselineTemp){ 
    //temperature is below baseline 
    digitalWrite(2, LOW); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){  
    digitalWrite(2, HIGH); 
    digitalWrite(3, LOW); 
    digitalWrite(4, LOW); 
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){ 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, LOW); 
  } else if(temperature >= baselineTemp+6){ 
    digitalWrite(2, HIGH); 
    digitalWrite(3, HIGH); 
    digitalWrite(4, HIGH); 
  } 
  delay(1); 
}


  
  
