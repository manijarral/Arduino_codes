const int echopin=51;
const int trigpin=50;
int relay = 3;
int led1=6;
int led2=7;
long duration;
int distance;
int sonar2()
{
  digitalWrite(trigpin2,LOW);
  digitalWrite(trigpin2,HIGH);
  delay(1000);
  digitalWrite(trigpin2,LOW);
  delay(1000);
  digitalWrite(echopin2,HIGH);
  distance=duration*0.34/2;
  Serial.print("Distance = ");
  Serial.println(distance);
}
void setup() {
pinMode(echopin,INPUT);
pinMode(trigpin,OUTPUT);
pinMode(relay,OUTPUT);
Serial.begin(9600);
}

void loop() {
digitalWrite(relay,HIGH);
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
duration=pulseIn(echopin,HIGH);
distance=duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

if(distance<205)
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW); 
 digitalWrite(relay,LOW); 
delay(2000);
}
else
{
 
 digitalWrite(led1,LOW);
 digitalWrite(led2,HIGH); 

}
}
