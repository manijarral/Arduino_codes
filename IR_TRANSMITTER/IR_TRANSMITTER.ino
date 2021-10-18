#include <IRremote.h>
#include <IRremoteInt.h>
IRsend irsend;

void setup()
{
 Serial.begin(9600);
}

void loop() 
{
   for (int i = 0; i <50; i++) { 
     irsend.sendRC5(0xA90, 12); // Sony TV power code
     delay(40);
   }
   delay(500);
}
