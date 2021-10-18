int pin1=13;
int pin2=12;

int arr[2]={pin1,pin2};
void setup() 
{
  // put your setup code here, to run once:
for(int i=0; i<2; i++)
{
  pinMode(arr[i],OUTPUT);
  digitalWrite(arr[i],LOW);//BY DEFAULT LED REMAINS LOW.
}
}
void loop()
{
  // put your main code here, to run repeatedly:
for(int j=0; j<2; j++)
{
  digitalWrite(arr[j], HIGH);
  delay(1000);
  digitalWrite(arr[j], LOW);
  delay(1000);
}
}
