const int LED=13;
void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogWrite(13,HIGH);
  //delay(5000);
  //digitalWrite(13,LOW);
  //delay(5000);
  int sensorValue=analogRead(A5);
  float voltage=sensorValue*(5.0/1023.0);
  analogWrite(4,voltage);
  Serial.println(voltage);
}
