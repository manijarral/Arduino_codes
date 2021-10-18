// variables
int GREEN=2;
int YELLOW=3;
int RED=4;
int button=13;
// variables will change:
int buttonState;         // variable for reading the pushbutton status

// basic functions
void setup()
{
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  buttonState=digitalRead(button);
  Serial.println(buttonState);
  if(buttonState==HIGH)
  {
  green_light();
  delay(5000);
  yellow_light();
  delay(2000);
  red_light();
  delay(5000);
  }
  else
  {
    digitalWrite(GREEN, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(RED, LOW);
  }
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}

void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}

void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
