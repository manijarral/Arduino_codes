int trigPin1=11;
int echoPin1=10;

int trigPin2=9;
int echoPin2=8;

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
}

void loop() 
{
int a=sonar1();
int b=sonar2();
  //sonar2();
  if( b<50 && a<50)
  {
     digitalWrite(G,LOW);
     digitalWrite(B,LOW);
     digitalWrite(R,HIGH);
     delay(5000);
  }
else
{
     digitalWrite(R,LOW);
     digitalWrite(G,LOW);
     digitalWrite(B,LOW);
}
if(a<50 && b<50)
{
     digitalWrite(G,HIGH);
     digitalWrite(R,LOW);
     digitalWrite(B,LOW);
    delay(5000);
}
else
    {
     digitalWrite(G,LOW);
     digitalWrite(R,LOW);
     digitalWrite(B,LOW);
    }
}
