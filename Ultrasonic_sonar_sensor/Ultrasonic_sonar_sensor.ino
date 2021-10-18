const int echopin=9;
const int trigpin=10;
int led=13;
//defines Variables.
long duration;
int distance;
void setup() {
  //trigger throws soundwaves.
  //echo recieves soundwaves.
  // put your setup code here, to run once:
pinMode(echopin,INPUT);//Sets the echopin as INPUT.
pinMode(trigpin,OUTPUT);//sets trigpin as OUTPUT.
Serial.begin(9600);//Starts the serial communication.
}

void loop() {
  // Clears the trigpin.
digitalWrite(trigpin, LOW);
delayMicroseconds(2);
//Sets the trigpin on HIGH state for 10 microseconds
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin, LOW);
//Reads the echopin, returns the soundwave travel time in microseconds.
duration=pulseIn(echopin,HIGH);
//calculating the distance
distance=duration*0.034/2;
//Prints the distance on the serial Monitor.
if(distance<50)
{
  digitalWrite(13,HIGH);
}
else
{
 digitalWrite(13,LOW); 
}
Serial.print("Distance: ");
Serial.println(distance);
}
