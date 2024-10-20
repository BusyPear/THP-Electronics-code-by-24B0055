#include <Wire.h>
// Define distance variable
int cm=0;
// Defines byte to send
int signal=0;

// Define function to calculate distance of object
long distance(int trig, int echo){
  pinMode(trig, OUTPUT);  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH);
}

// Handler function for onRequest()
void stopMotor(){
  Wire.write(signal);
  Serial.print("Byte sent: ");
  Serial.println(signal);
}

void setup(){
  Serial.begin(9600);
  Wire.begin(7);
}

void loop(){
  // Calculate distance from speed of sound
  cm = 0.01723*distance(7,6);
  Serial.print(cm);
  Serial.println("cm");
  // Send correct byte when object is near
  if (cm<=15){
    signal=1;
    Wire.onRequest(stopMotor);
  }
  // Send byte to be ignored by master when no objct is near
  else{
    signal=0;
  }
  delay(100);
}
