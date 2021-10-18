#include <DHT.h>

#define DHT_apin A0 // Analog Pin sensor is connected to
 
DHT DHT;

#include <Servo.h>
Servo servo;
int angle = 10;

void setup() 
{
  servo.attach(8);
  servo.write(angle);
  
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop() 
{
    DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    delay(5000);
 
  
  if(DHT.humidity>80 && DHT.temperature>25)
  {
   for(angle = 10; angle < 360; angle++)  
  {                                  
    servo.write(angle);               
    delay(1);                   
  } 
  }
  else if(DHT.humidity>30 && DHT.temperature>25)
    {
   for(angle = 10; angle < 360; angle++)  
  {                                  
    servo.write(angle);               
    delay(1);                   
  }  
    }
  else
  {
   for(angle = 360; angle > 10; angle--)    
  {                                
    servo.write(angle);           
    delay(1);       
  }
  }
}
