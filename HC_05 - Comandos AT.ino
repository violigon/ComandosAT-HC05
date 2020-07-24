#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX|TX

void setup() 
{
  pinMode(9, OUTPUT); 
  digitalWrite(9, HIGH); 
  Serial.begin(57600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(38400);  
}

void loop()
{
  if (BTSerial.available())
    Serial.write(BTSerial.read());
    
  if (Serial.available())
    BTSerial.write(Serial.read());
}
