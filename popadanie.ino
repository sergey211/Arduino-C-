/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.
*/
int pin = analogRead(A0);
int pin1 = 0;
int pinMin;
int pinAverage; 
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
delay (1000);
  for (int i = 0; i < 20; i++)
{
  int pin = analogRead(A0);
   pin1 = pin1+pin;
   Serial.print("pin1=");
   Serial.println(pin);
   delay (1000);
}
   pinAverage = pin1/20;
   Serial.print("pinAverage=");
   Serial.println(pinAverage);
   pinMin = pinAverage-10;
   Serial.print("pinMin=");
   Serial.println(pinMin);
   delay (3000);
}


// the loop routine runs over and over again forever:
void loop() {
  int pin = analogRead(A0);
  // read the input on analog pin 0:
  
  // print out the value you read:
  Serial.println(pin);
  
  if (pin < pinMin)
  {  Serial.println("!!!popadanie!!!");}
  delay(1);        // delay in between reads for stability
}
