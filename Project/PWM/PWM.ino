int enablePin = A1;
int in1Pin = 10;
int in2Pin = 9;

void setup()
{
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(enablePin, OUTPUT);
}
 
void loop()
{
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  analogWrite(enablePin, 150);
  delay(1000);
  analogWrite(enablePin, 255);
  delay(1000);
}
 
