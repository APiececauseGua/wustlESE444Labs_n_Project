#include <WiFi101.h> 
#include<WiFiSSLClient.h> 
const char* ssid = "ASUS_Jason";    //  your network SSID (name) 
const char* password = "173380439";  // your network password 
String httpsRequest = "https://hooks.zapier.com/hooks/catch/9535699/opfxjq6/";// your Zapier URL 
const char* host = "hooks.zapier.com"; 
WiFiSSLClient client; 
void setup() { 
 Serial.begin(9600); 
 while (!Serial); 
 delay(2000); 
 Serial.print("Connecting Wifi: "); 
 Serial.println(ssid); 
 while (WiFi.begin(ssid, password) != WL_CONNECTED) { 
   Serial.print("."); 
   delay(500); 
 } 
 Serial.println(""); 
 Serial.println("WiFi connected"); 
} 
void loop() { 
 float temperature = 22; 
 int moisture = 150; 
 int light = 40; 
 String warning = "This is a warning message"; 
 warning.replace(" ", "%20"); 
 send_email(temperature, moisture, light, warning ); 
 delay(20000);
 exit(0); 
} 
void send_email(float temperature, int moisture, int light, String warning) { 
 // convert values to String 
 String _temperature = String(temperature); 
 String _moisture = String(moisture); 
 String _light = String(light); 
 String _warning = warning; 
 if (client.connect(host, 443)) { 
   client.println("POST " + httpsRequest + "?temperature=" + _temperature + "&moisture=" + _moisture + "&light=" + _light + "&warning=" + _warning + " HTTP/1.1"); 
   client.println("Host: " + String(host)); 
   client.println("Connection: close"); 
   client.println(); 
   delay(1000); 
   while (client.available()) { // Print on the console the answer of the server 
     char c = client.read(); 
     Serial.write(c); 
   } 
   client.stop();  // Disconnect from the server 
 } 
 else { 
   Serial.println("Failed to connect to client"); 
 } 
}  
