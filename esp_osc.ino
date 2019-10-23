#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

// All of this code works! It transmits ambient light sensor data over Wifi. We weren't getting great resolution 
// with our sensor but I think that had more to do with how we wired it.

/* Put your SSID & Password */
const char* ssid = "~XXXWifi~";  // Enter SSID here
const char* password = "1123581321";  //Enter Password here

int ambientPin = 34;
int forcePin = 33;
int touchPin = 32;

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);

  pinMode(ambientPin, INPUT);
  pinMode(forcePin, INPUT);
  pinMode(touchPin, INPUT);

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
  server.begin();
}

void loop(){

      int light_value = analogRead(ambientPin);
      int light = light_value * 0.5;

      int force_value = analogRead(forcePin);

      int touch_value = analogRead(touchPin);
  
    udp.beginPacket("192.168.1.2", 3890);
    udp.print(String(light) + " " + String(force_value) + " " + String(touch_value));
    udp.endPacket();
  
  //Wait for 1 second
    delay(1000);
  
}
