// variables
int GREEN=12;
int button=13;
// variables will change:
int buttonState;         // variable for reading the pushbutton status

// basic functions
void setup()
{
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  buttonState=digitalRead(button);
  Serial.println(buttonState);
  if(buttonState==HIGH)
  {
  digitalWrite(GREEN, HIGH);

  }
  else
  {
    digitalWrite(GREEN, LOW);
  }
}
