#include <Servo.h>
Servo servo;
int angle = 10;
const int echopin=9;
const int trigpin=10;
//defines Variables.
long duration;
int distance;
void setup()
{
servo.attach(8);
servo.write(angle);
pinMode(echopin,INPUT);//Sets the echopin as INPUT.
pinMode(trigpin,OUTPUT);//sets trigpin as OUTPUT.
Serial.begin(9600);//Starts the serial communication.
}

void loop() {
  // Clears the trigpin.
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
//Sets the trigpin on HIGH state for 10 microseconds
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
//Reads the echopin, returns the soundwave travel time in microseconds.
duration=pulseIn(echopin,HIGH);
//calculating the distance
distance=duration*0.034/2;
//Prints the distance on the serial Monitor.
  if(distance<50)
  {
    for(angle; angle < 360; angle++)  
  {                                  
    servo.write(angle);               
    delay(1);                   
  } 
  }
  else if(distance>50 && distance<100)
  {
  // now scan back from 180 to 0 degrees
  for(angle; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(1);       
  }
  }
Serial.print("Distance: ");
Serial.println(distance);
}
