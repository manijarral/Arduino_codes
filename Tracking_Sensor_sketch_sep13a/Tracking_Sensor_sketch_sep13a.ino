const int RED=13;
const int GREEN=12;
const int BLUE=11;
int Sensor=A5;
int SensorValue=0;
void red_light()
{
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

void green_light()
{
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
}

void blue_light()
{
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}
void off()
{
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW); 
}
void led()
{
  red_light();
  delay(500);
  green_light();
  delay(500);
  blue_light();
  delay(500);
}
void setup() {
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(Sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  SensorValue=analogRead(Sensor);
  if(SensorValue<50&&SensorValue<500)
  {
    led();
    Serial.println(SensorValue,DEC);
  }
  else(SensorValue>500&&SensorValue>1023);
  {
    off();
    Serial.println(SensorValue,DEC);
  }
}
