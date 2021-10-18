const int RED=13;
const int GREEN=12;
const int BLUE=11;
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
void led()
{
  red_light();
  delay(500);
  green_light();
  delay(500);
  blue_light();
  delay(500);
}
void setup()
{
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(BLUE,OUTPUT);
}

void loop() {
  led();
}
