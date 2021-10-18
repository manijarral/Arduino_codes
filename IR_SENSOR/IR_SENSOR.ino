#include <IRremote.h>
IRsend irsend;
int RECV_PIN = 11; // define input pin on Arduino 
IRrecv irrecv(RECV_PIN); 
decode_results results; // decode_results class is defined in IRremote.h

void setup()
{
 Serial.begin(9600);
 irrecv.enableIRIn();
}

void loop() 
{
    if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); 
    irrecv.resume(); // Receive the next value 
  }
  delay (100);
   for (int i = 0; i < 50; i++) { 
     irsend.sendSony(0xa90, 12); // Sony TV power code
     delay(40);
   }
}
