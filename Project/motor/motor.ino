int potPin = 6;

void setup(){
  pinMode(6, OUTPUT);
}

void loop(){
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
  Serial.println("light!");
  
}
