int red = 11; // define the LED pin
int green=10;
int digitalPin = 2; // KY-026 digital interface
int analogPin = A0; // KY-026 analog interface
int digitalVal; // digital readings
int analogVal; //analog readings

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(digitalPin, INPUT);
  //pinMode(analogPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin); 
  if(digitalVal == HIGH) // if flame is detected
  {
    analogWrite(green, 255);
    analogWrite(red, 0);
  }
  else
  {
    analogWrite(red, 255);
    analogWrite(green, 0);// turn OFF Arduino's LED
  }  // Read the analog interface
  analogVal = analogRead(analogPin); 
  Serial.println(digitalVal); // print analog value to serial

  delay(100);
}
