#include <RTCZero.h> 
RTCZero rtc; // create RTC object 
/* Change these values to set the current initial time */ 
const byte seconds = 0; 
const byte minutes = 0; 
const byte hours = 16; 
/* Change these values to set the current initial date */ 
const byte day = 4; 
const byte month = 12; 
const byte year = 17; 
bool email_already_sent = false; 
void setup() { 
 Serial.begin(9600); 
 while (!Serial); 
 delay(2000); 
 rtc.begin(); // initialize RTC 24H format 
 rtc.setTime(hours, minutes, seconds); 
 rtc.setDate(day, month, year); 
 rtc.setAlarmTime(16, 1, 0);  // Set the time for the Arduino to send the email 
 rtc.enableAlarm(rtc.MATCH_HHMMSS); 
 rtc.attachInterrupt(alarmMatch); 
} 
void loop() { 
 if (!email_already_sent) { 
   // send_email(); 
   email_already_sent = true; 
 } 
} 
void alarmMatch() { // triggered when the alarm goes on 
 Serial.println("Alarm Match!"); 
 email_already_sent = false; 
} 
