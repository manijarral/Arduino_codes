int Sensor = 10; // Declaration of the sensor input pin
void setup ()
{
 Serial.begin(9600); // Initialization serial output
 pinMode (Sensor, INPUT) ; // Initialization sensor pin
}
// The program reads the current status of the sensor pin
// shows via serial console if the sensor detects a obstacle or not
void loop ()
{
 bool val = digitalRead (Sensor) ; // The current signal at the sensor will be read
 if (val == HIGH) // If a signal is detected, the LED will light up.
 {
 Serial.println("No obstacle");
 }
 else
 {
 Serial.println("Obstacle detected");
 }
 Serial.println("------------------------------------");
 delay(500); // Break of 500ms between each measurement
}
