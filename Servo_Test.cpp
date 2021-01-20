#include <Servo.h>

Servo myServo;

int servoPin = 9;
int servoPos = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
    myServo.write(servoPos);
    if (servoPos == 0) {
      servoPos = 160;
   } else if (servoPos == 160) {
    servoPos = 0;
   }
  delay(1000); 
}
