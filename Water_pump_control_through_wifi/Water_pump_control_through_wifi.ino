int relayPin = 13;//define a pin for relay
String buttonTitle1 ="Light ON";
String buttonTitle2 ="Light OFF";

int relayStat = 0;//initial state . 1 ON, 0 OFF

#define BLYNK_PRINT Serial
#include <BlynkSimpleEsp32.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESPmDNS.h>

char auth[] = "0Ihoj6c3UM2JmO8NEhMzoOmex0pmNdbH";

const char *ssid = "Test";
const char *password = "Must@123";


const int led = 12;


 digitalWrite(led, 1);  


void setup(void) {
  //Robojax.com ESP32 Relay Control 
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);  
  pinMode(relayPin, OUTPUT);// define a pin as output for relay
  digitalWrite(relayPin, relayStat);//initial state either ON or OFF
  Serial.begin(115200);//initialize the serial monitor

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Blynk.config(auth);
  Serial.println("");
 // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

  void loop() {
  Blynk.run();

}
