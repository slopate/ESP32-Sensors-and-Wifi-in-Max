#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

// All of this code works! It transmits ambient light sensor data over Wifi. We weren't getting great resolution 
// with our sensor but I think that had more to do with how we wired it.

/* Put your SSID & Password */
const char* ssid = "~XXXWifi~";  // Enter SSID here
const char* password = "11235813";  //Enter Password here

int ambientPin = 34;
int flexPin = 33;
int touchPin = 35;

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  server.begin();

  pinMode(ambientPin, INPUT);
  pinMode(flexPin, INPUT);
  pinMode(touchPin, INPUT);
}

void loop(){

    int light_value = analogRead(ambientPin);
    int light = light_value * 0.0976;

    int flex_value = analogRead(flexPin);

    int touch_value = analogRead(touchPin);

    Serial.println(String(light) + " " + String(flex_value));
  
    udp.beginPacket("192.168.1.2", 3980);
    udp.print(String(light) + " " + String(flex_value));
    udp.endPacket();
  
  //Wait for 1 second
  delay(3000);
  
}
