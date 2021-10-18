int sensorPin = 2; //define analog pin 2
int value = 0;
int led1 = 13;
int led2 = 12;
int led3 = 11;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(sensorPin);
  Serial.println(value, DEC); // light intensity
  // high values for bright environment
  // low values for dark environment
  delay(100);
  if (value > 0 && value< 100)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  else if (value > 100 && value <200)
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
  }
  else if (value < 200)
  { digitalWrite(led3, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  }
}
