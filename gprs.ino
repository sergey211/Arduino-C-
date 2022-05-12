#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5); // RX, TX (НА ШИЛДЕ TX=4, RX=5)

void setup()  

{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
//  while (!Serial) {
 //   ; // wait for serial port to connect. Needed for Leonardo only
 // }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  mySerial.println("Hello, world?");
  pinMode(9, OUTPUT);
}

void loop() // run over and over
{
  digitalWrite(9, HIGH);
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());
}


