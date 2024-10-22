#include <Wire.h>
// Condition variable for not letting code for turning on 
// the motor execute if motor is stopped
int cond=1;
// Handler function for onRecieve()
void stop(int nBytes){
  if (Wire.available()){
    digitalWrite(2,LOW);
    Serial.println("Motor stopped");
    // Used to consume the byte received so 
    // available bytes go to zero
    int c=Wire.read();
    cond=0;
    delay(100);	
  }
}

void setup(){
  Serial.begin(9600);
  Wire.begin(8);
  pinMode(2,OUTPUT);
}

void loop(){
  Wire.onReceive(stop);
  // Turns on motor if signal is not received
  if (cond){
  	digitalWrite(2,HIGH);
  	Serial.println("Motor working");
  }
  // Default value of condition variable
  cond=1;
  delay(100);
}

