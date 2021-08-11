int redPin = 6; 
int greenPin = 8; 
int bluePin = 7; 
int motorPin = 9;

void setup()                                
{
  Serial.begin(9600);      

  pinMode(redPin, OUTPUT); 
  pinMode(greenPin, OUTPUT); 
  pinMode(bluePin, OUTPUT); 
  pinMode(motorPin, OUTPUT);
}

void loop()                                  
{
  Serial.print("A3 = ");                     
  Serial.print(volts(A3));                    
  Serial.println(" volts");                  
  if(volts(A3)<=2.0){
    setColor(255, 0, 0); // red 
    setFan(135);
    Serial.print("red");  
  }
  if(volts(A3)>2.0){
    setColor(0, 255, 0); // green
    setFan(255);
  }
   
/*
  setColor(0, 255, 0); // green 
  delay(1000);
  setColor(255, 255, 0); // yellow
  delay(1000);
  setColor(255, 0, 0); // red 
*/
}
                                             
float volts(int Pin)                       
{                                            
 return float(analogRead(Pin)) * 5.0 / 1024.0;
}    

// Send RGB values to the LED pins 
void setColor(int red, int green, int blue){ 
 analogWrite(redPin, red); 
 analogWrite(greenPin, green); 
 analogWrite(bluePin, blue);   
} 

void setFan(int speed){
    analogWrite(motorPin, speed);
}
