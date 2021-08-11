int moisturePin = A2; 
int threshold = 800; 

int tempPin = A1;
int redPin = 6; 
int greenPin = 8;
int bluePin = 7; 

int touchPin = A3;

int in1Pin = 10;
int in2Pin = 9;
int motorPin = A4;
bool touchSwitch = true;

int setT = 29;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  //while (!Serial); 
  //delay(2000); 

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  get_temperature();
  get_average_moisture(); 
  if(volts(touchPin)<=1.5)//stop
  { 
    delay(1000);
    if(volts(touchPin)<=1.5){
      touchSwitch = !touchSwitch;
      Serial.print("touched!");
    }
  }
  if(touchSwitch){                    //touch turn on
    if(get_average_moisture()>=threshold){
      if(get_temperature()>=setT){
        setColor(0, 255, 0);          // green
        setFan(255);
        Serial.println("Too hot");
      }
      else{
        setColor(255, 0, 0);          //red
        setFan(100);
        Serial.println("Too cold");
      }
    }
    if(get_average_moisture()<threshold){
      setColor(0, 0, 255);            //blue
      setFan(100);
      Serial.println("Too wet");
     }
  }
  if(!touchSwitch){                //touch turn off
    setColor(255, 0, 0);                //red
    setFan(0);                          //switch turn off, fan off
    Serial.println("turn off and stop fan");
  }
}   


//moisture
float get_average_moisture() {           // make an average of 10 values to be more accurate 
 float tempValue = 0;                    // variable to temporarly store moisture value 
 for (int a = 0; a < 10; a++) { 
   tempValue += analogRead(moisturePin); 
 } 

 Serial.print("M:");
 Serial.println(tempValue / 10);
 return tempValue / 10; 
} 

//temperature
float get_temperature(){
  int reading = analogRead(tempPin);  
  float voltage = reading * 3.3;
  voltage /= 1024.0; 
  
 // Print tempeature in Celsius
 float temperatureC = (voltage - 0.5) * 100 ; //converting from 10 mv per degree wit 500 mV offset

 // Convert to Fahrenheit
 float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

 Serial.print("T:");
 Serial.println(temperatureC);
 return temperatureC;
}

// Send RGB values to the LED pins 
void setColor(int red, int green,int blue){ 
 analogWrite(redPin, red); 
 analogWrite(greenPin, green);  
 analogWrite(bluePin, blue); 
} 

//
float volts(int Pin)                       
{                                            
 return float(analogRead(Pin)) * 5.0 / 1024.0;
}    

void setFan(int speed){
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  analogWrite(motorPin, speed);
}
