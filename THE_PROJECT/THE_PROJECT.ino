int trigPin1=8;
int echoPin1=9;

int relay1=3;
int relay2=4;

int trigPin2=50;
int echoPin2=51;

int R=7;
int G=6;
int B=5;
  long duration1;
  int distance1;
  long duration2;
  int distance2;
int sonar1()
{
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  Serial.print ( "Sensor1 ");
  Serial.print ( distance1);
  Serial.println("cm");
  delay(100);
  return distance1;
}
int sonar2()
{
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;
  Serial.print("Sensor2 ");
  Serial.print(distance2);
  Serial.println("cm");
  delay(100);
  return distance2;
}

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
}

void loop() 
{
digitalWrite(relay1,HIGH);
digitalWrite(relay2,HIGH);
int a=sonar1();
int b=sonar2();
if(distance1<205)
{
 digitalWrite(relay1,LOW); 
delay(2000);
if(distance2<205)
{
  
  digitalWrite(G,HIGH);
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
}
}
else
{
  digitalWrite(G,LOW);
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
}
if(distance2<35)
{
  digitalWrite(relay2,LOW);
  delay(2000);
  if(distance1<35)
  {
    digitalWrite(G,LOW);
    digitalWrite(R,HIGH);
    digitalWrite(B,LOW);
  }
}
else
{
  digitalWrite(G,LOW);
  digitalWrite(R,LOW);
  digitalWrite(B,LOW);
}
}
