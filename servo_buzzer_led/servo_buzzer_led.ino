#include<Servo.h>
Servo servo;
int angle=10;
const int echo=22;
const int trig=24;
const int buzzer=28;
int led=13;
long duration;
int distance;
void setup()
{
  servo.attach(8);
  servo.write(angle);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
duration=pulseIn(echo,HIGH);
distance=duration*0.034/2;
if(distance<25)
{
  for(angle; angle<180; angle++)
  {
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    servo.write(angle);
    delay(1);
  }
}
else if(distance>25 && distance<100)
{
  for(angle; angle>10; angle--)
  {
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
    servo.write(angle);
    delay(1);
  }
}
Serial.print("Distance: ");
Serial.println(distance);
}
