int trigPin1=11;
int echoPin1=10;

int trigPin2=9;
int echoPin2=8;

int trigPin3=13;
int echoPin3=12;

int R=7;
int G=6;
int B=5;
  long duration1;
  int distance1;
  long duration2;
  int distance2;
  long duration3;
  int distance3;
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
int sonar3()
{
  digitalWrite(trigPin3, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distance3= duration3*0.034/2;
  Serial.print("Sensor3 ");
  Serial.print(distance3);
  Serial.println("cm");
  delay(100);
  return distance3;
}
void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() 
{
int a=sonar1();
int b=sonar2();
int c=sonar3();
  //sonar2();
  if( a<50 && b<50)
  {
     digitalWrite(G,LOW);
     digitalWrite(B,LOW);
     digitalWrite(R,HIGH);
    }
    else
    {
      digitalWrite(G,LOW);
      digitalWrite(B,LOW);
      digitalWrite(R,LOW);
    }
    delay(1000);
  }
else if(b<50 && a<50)
{
     digitalWrite(G,HIGH);
     digitalWrite(R,LOW);
     digitalWrite(B,LOW);
    }
    else
    {
     digitalWrite(G,LOW);
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
}
