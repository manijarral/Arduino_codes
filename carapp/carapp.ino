const int freq = 5000;
const int resolution = 8;
const int ledChannel = 0;
const int ledChannel1 = 0;
const int ledChannel2 = 0;
const int ledChannel3 = 0;

int M1pin1 = 12;
int M1pin2 = 14;

int M2pin1 = 27;
int M2pin2 = 26;

int M3pin1 = 18;
int M3pin2 = 19;

int M4pin1 = 33;
int M4pin2 = 32;

int RPM1 = 13;
int RPM2 = 25;
int RPM3 = 5;
int RPM4 = 21;

int PWM_value = 250;

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "e4JIt92LG4NmvGgRQWJ1475kS8fjsfeg";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Andriod";
char pass[] = "12345678";
int LED=2;
//WidgetLED led1(V1);

//BlynkTimer timer;

BLYNK_WRITE(V1) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 Serial.println(pinValue);
 if (pinValue == 2) {
   //led1.off();
   Serial.println("LED on V1: off");
    digitalWrite(M1pin1, HIGH); // Turn LED on.
    digitalWrite(M1pin2, LOW);
    ledcWrite(ledChannel, PWM_value);
    digitalWrite(M2pin1, HIGH); // Turn LED on.
    digitalWrite(M2pin2, LOW);
    ledcWrite(ledChannel1, PWM_value);
    digitalWrite(M3pin1, HIGH); // Turn LED on.
    digitalWrite(M3pin2, LOW);
    ledcWrite(ledChannel2, PWM_value);
    digitalWrite(M4pin1, HIGH); // Turn LED on.
    digitalWrite(M4pin2, LOW);
    ledcWrite(ledChannel3, PWM_value);
  } else {
     //led1.on();
     Serial.println("LED on V1: on");
   digitalWrite(M1pin1, LOW); // Turn LED on.
    digitalWrite(M1pin2, LOW);
    ledcWrite(ledChannel, PWM_value); // Turn LED off.
     digitalWrite(M2pin1, LOW); // Turn LED on.
    digitalWrite(M2pin2, LOW);
    ledcWrite(ledChannel1, PWM_value);
     digitalWrite(M3pin1, LOW); // Turn LED on.
    digitalWrite(M3pin2, LOW);
    ledcWrite(ledChannel2, PWM_value);
     digitalWrite(M4pin1, LOW); // Turn LED on.
    digitalWrite(M4pin2, LOW);
    ledcWrite(ledChannel3, PWM_value);
 }
}

BLYNK_WRITE(V2) {
  
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 Serial.println(pinValue);
 if (pinValue == 2) {
   //led1.off();
   Serial.println("LED on V1: off");
    digitalWrite(M4pin1, HIGH); // Turn LED on.
    digitalWrite(M4pin2, LOW);
    ledcWrite(ledChannel, PWM_value);
     digitalWrite(M1pin1, HIGH); // Turn LED on.
    digitalWrite(M1pin2, LOW);
    ledcWrite(ledChannel, PWM_value);
  } else {
     //led1.on();
     Serial.println("LED on V1: on");
   digitalWrite(M4pin1, LOW); // Turn LED on.
    digitalWrite(M4pin2, LOW);
    ledcWrite(ledChannel, PWM_value); // Turn LED off.
     digitalWrite(M1pin1, LOW); // Turn LED on.
    digitalWrite(M1pin2, LOW);
    ledcWrite(ledChannel, PWM_value);
 }
}

BLYNK_WRITE(V3) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 Serial.println(pinValue);
 if (pinValue == 2) {
   //led1.off();
   Serial.println("LED on V1: off");
    digitalWrite(M3pin1, HIGH); // Turn LED on.
    digitalWrite(M3pin2, LOW);
    ledcWrite(ledChannel, PWM_value);
    digitalWrite(M2pin1, HIGH); // Turn LED on.
    digitalWrite(M2pin2, LOW);
    ledcWrite(ledChannel1, PWM_value);
  } else {
     //led1.on();
     Serial.println("LED on V1: on");
   digitalWrite(M3pin1, LOW); // Turn LED on.
    digitalWrite(M3pin2, LOW);
    ledcWrite(ledChannel, PWM_value); // Turn LED off.
    digitalWrite(M2pin1, LOW); // Turn LED on.
    digitalWrite(M2pin2, LOW);
    ledcWrite(ledChannel1, PWM_value);
 }
}

BLYNK_WRITE(V4) {
 int pinValue = param.asInt(); // Assigning incoming value from pin V3 to a variable
 Serial.println(pinValue);
 if (pinValue == 2) {
   //led1.off();
   Serial.println("LED on V1: off");
    digitalWrite(M1pin1, LOW); // Turn LED on.
    digitalWrite(M1pin2, HIGH);
    ledcWrite(ledChannel, PWM_value);
    digitalWrite(M2pin1, LOW); // Turn LED on.
    digitalWrite(M2pin2, HIGH);
    ledcWrite(ledChannel1, PWM_value);
    digitalWrite(M3pin1, LOW); // Turn LED on.
    digitalWrite(M3pin2, HIGH);
    ledcWrite(ledChannel2, PWM_value);
    digitalWrite(M4pin1, LOW); // Turn LED on.
    digitalWrite(M4pin2, HIGH);
    ledcWrite(ledChannel3, PWM_value);
  } else {
     //led1.on();
     Serial.println("LED on V1: on");
   digitalWrite(M1pin1, LOW); // Turn LED on.
    digitalWrite(M1pin2, LOW);
    ledcWrite(ledChannel, PWM_value); // Turn LED off.
     digitalWrite(M2pin1, LOW); // Turn LED on.
    digitalWrite(M2pin2, LOW);
    ledcWrite(ledChannel1, PWM_value);
     digitalWrite(M3pin1, LOW); // Turn LED on.
    digitalWrite(M3pin2, LOW);
    ledcWrite(ledChannel2, PWM_value);
     digitalWrite(M4pin1, LOW); // Turn LED on.
    digitalWrite(M4pin2, LOW);
    ledcWrite(ledChannel3, PWM_value);
 }
}
// V1 LED Widget is blinking
//void blinkLedWidget()
//{
//  if (led1.getValue()) {
//    led1.off();
//    Serial.println("LED on V1: off");
//  } else {
//    led1.on();
//    Serial.println("LED on V1: on");
//  }
//}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  pinMode(M1pin1,OUTPUT);
  pinMode(M1pin2,OUTPUT);
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(RPM1, ledChannel);
  
  pinMode(M2pin1,OUTPUT);
  pinMode(M2pin2,OUTPUT);
  ledcSetup(ledChannel1, freq, resolution);
  ledcAttachPin(RPM2, ledChannel1);
  
  pinMode(M3pin1,OUTPUT);
  pinMode(M3pin2,OUTPUT);
  ledcSetup(ledChannel2, freq, resolution);
  ledcAttachPin(RPM3, ledChannel2);
  
  pinMode(M4pin1,OUTPUT);
  pinMode(M4pin2,OUTPUT);
  ledcSetup(ledChannel3, freq, resolution);
  ledcAttachPin(RPM4, ledChannel3);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
pinMode(LED,OUTPUT);
  //timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
 // timer.run();
}
