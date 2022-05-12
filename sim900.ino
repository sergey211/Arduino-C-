#include <SoftwareSerial.h>
#include <GPRS_Shield_Arduino.h>
GPRS gprs(Serial1); // RX, TX (НА ШИЛДЕ TX=4, RX=5)
void setup()  
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
 // Serial1.begin(9600);
//  while (!Serial) {
 //  wait for serial port to connect. Needed for Leonardo only
 // }
  Serial.println("Goodnight moon!");
  // set the data rate for the SoftwareSerial port
 Serial1.begin(9600);
  Serial1.println("Hello, world?");
}
void loop() // run over and over
{
  if (Serial1.available())
    Serial.write(Serial1.read());
  if (Serial.available())
 Serial1.write(Serial.read());
}

