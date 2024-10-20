// Define digital pins
int d0=2;
int d1=3;
int d2=4;
int d3=5;
void setup(){
  // Configure digital pins
  pinMode(d0, INPUT);
  pinMode(d1, INPUT);
  pinMode(d2, INPUT);
  pinMode(d3, INPUT);
  Serial.begin(9600);
}
// Define binary bits
int a,a0,a1,a2,a3;
void loop(){
  // Read bits
  a0=digitalRead(d0);
  a1=digitalRead(d1);
  a2=digitalRead(d2);
  a3=digitalRead(d3);
  // Convert binary number to its decimal equivalent
  a=a3*8+a2*4+a1*2+a0;
  // Print binary number
  Serial.print("Binary number: ");
  Serial.print(a3);
  Serial.print(a2);
  Serial.print(a1);
  Serial.println(a0);
  // Print decimal number
  Serial.print("Decimal equivalent: ");
  Serial.println(a);
  delay(1000);
}