int ms;
int s;
int m;
int h;
  
void setup()   
{  
    Serial.begin(9600);  
}  
  
void loop()   
{
  for(h=0;h<=24;h++)
  {
  for(m=0;m<=60;m++)
  {
  for(s=0;s<=60;s++)
  {
  for(ms=1;ms<=60;ms++)
  {
    delay(0);
    Serial.print("h");
    Serial.print(h);
    Serial.print(" ");
    Serial.print("m");
    Serial.print(m);
    Serial.print(" ");
    Serial.print("s");
    Serial.print(s);
    Serial.print(" ");
    Serial.print("ms");
    Serial.println(ms);
  }
 }
}
}
}
