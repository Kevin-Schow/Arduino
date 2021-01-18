//header
//define variables and constants

int switchState = 0;


//setup
// the setup routine runs once when you press reset:

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT); 
}


//loop
// the loop routine runs over and over again forever:

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    digitalWrite(3, HIGH);  // green LED on
    digitalWrite(4, LOW);  // red LED off
    digitalWrite(5, LOW); // red LED off 
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    delay (250); //wait a quarter second
    //toggle the red LEDs 
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay (250);
  }
}
