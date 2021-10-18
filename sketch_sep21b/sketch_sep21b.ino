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
  for(h=59;h<=24;h++)
  {
  for(m=59;m<=60;m++)
  {
  for(s=58;s<=60;s++)
  {
  for(ms=1;ms<=60;ms++)
  {
    delay(0);
    Serial.print(h);
    Serial.print(" ");
    Serial.print(m);
    Serial.print(" ");
    Serial.print(s);
    Serial.print(" ");
    Serial.println(ms);
  }
   // if(ms==60)
    //{
     // ms=0;
    //}
}
//  if(s==60)
 // {
   // s=0;
  //}
}
  //if(m==60)
  //{
   // m=0;
  //}
}
//if(h==24)
//{
 // h=0;
//}
}
