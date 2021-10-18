const int echopin=10;
const int trigpin=9;
//defines Variables.
long duration;
int distance;
float sonar(int trigpin1,int echopin2)
{
   // Clears the trigpin.
digitalWrite(trigpin1, LOW);
delayMicroseconds(2);
//Sets the trigpin on HIGH state for 10 microseconds
digitalWrite(trigpin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin1, LOW);
//Reads the echopin, returns the soundwave travel time in microseconds.
duration=pulseIn(echopin2,HIGH);
//calculating the distance 
distance=duration*0.034/2;
return distance;
}
void setup() {
  //trigger throws soundwaves.
  //echo recieves soundwaves.
  // put your setup code here, to run once:
pinMode(echopin,INPUT);//Sets the echopin as INPUT.
pinMode(trigpin,OUTPUT);//sets trigpin as OUTPUT.
Serial.begin(9600);//Starts the serial communication.
}

void loop() {
float result=sonar(trigpin,echopin);

//Prints the distance on the serial Monitor.
Serial.print("Distance: ");
Serial.println(result);
}
