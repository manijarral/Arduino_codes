int trigPin1=11;
int echoPin1=10;

int trigPin2=9;
int echoPin2=8;

int green=13;
int red=12;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
   pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop() {
  long duration1, distance1;
  digitalWrite(trigPin1, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;

   if (distance1 >= 500 || distance1 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print ( "Sensor1 ");
    Serial.print ( distance1);
    Serial.println("cm");
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
  }
  delay(500);
long duration2, distance2;
  digitalWrite(trigPin2, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2= duration2*0.034/2;

   if (distance2 >= 500 || distance2 <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print("Sensor2 ");
    Serial.print(distance2);
    Serial.println("cm");
    digitalWrite(green,HIGH);
    digitalWrite(red,HIGH);
  }
  delay(500);
}
