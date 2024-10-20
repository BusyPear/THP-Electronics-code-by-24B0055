// Define Arduino pins for enable and input pins
const int ENA=10;
const int ENB=11;

const int IN1=2;
const int IN2=3;
const int IN3=4;
const int IN4=5;

// Define variable to denote duration of 5 motor rotations
float wait;
// Arrays for path length in units of motor rotations, 
// seperated according to right(lengthr) or left(lengthl) turns
int lengthr[]={15,10,15,5};
int lengthl[]={10,5,10};
void setup(){
  Serial.begin(9600);
  // Pin configurations
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  // HIGH voltage on enable pins for constant speed of motors
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
}

void loop(){
  // Trip from D to C (they only have right turns)
  for (int i=0; i<4; i++) {
    // Trip from D to B
    Serial.print("Going straight, ");
    // The motors looked like they would make humanoid
    // go straight(cheacked motor at low speeds to see rotation)
    // with these signals: 
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    // Time taken (in miliseconds) for motor to 
    // complete 5 rotations = 5*60*1000/244 = 1229.5
    wait=1298.7*lengthr[i]/5;
    delay(wait);
    Serial.print("Time taken: ");
    Serial.print(wait);
    Serial.println("ms");
    // Turning right
    Serial.print("Turning right, ");
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    // Assuming bot takes 500ms to turn 90 degrees 
    // in any direction
    delay(500);
    Serial.println("Time taken: 500ms");
  }
  for (int j=0; j<3; j++) {
    // Trip from B to D (they only have left turns)
    Serial.print("Going straight, ");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    // Time taken (in miliseconds) for motor to 
    // complete 5 rotations = 5*60*1000/244 = 1229.5
    wait=1298.7*lengthl[j]/5;
    delay(wait);
    Serial.print("Time taken: ");
    Serial.print(wait);
    Serial.println("ms");
    // Turning left
    Serial.print("Turning left, ");
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);
    // Assuming bot takes 500ms to turn 90 degrees 
    // in any direction
    delay(500);
    Serial.println("Time taken: 500ms");
  }
  // Have to turn left again for about turn at D
  Serial.println("Turning left again for about turn, Time taken: 500ms");
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  // Assuming bot takes 500ms to turn 90 degrees 
  // in any direction
  delay(500);
  Serial.println("Trip restarting");
}