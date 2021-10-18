#include <Servo.h>
Servo servo;
int angle = 10;
void setup() {
  servo.attach(8);
  servo.write(angle);
}
void loop() 
{ 
 // scan from 0 to 180 degrees
  if(distance<50)
  {
    for(angle = 10; angle < 360; angle++)  
  {                                  
    servo.write(angle);               
    delay(1);                   
  } 
  }
  else(distace>50 && distance<100)
  {
  // now scan back from 180 to 0 degrees
  for(angle = 360; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(1);       
  }
  }
}
