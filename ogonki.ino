/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
    
int randNumber;
int rand2;
int var;
int pin;
int fadeValue;
int pause;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
     pinMode(2, OUTPUT);
     pinMode(6, OUTPUT);
     Serial.begin(9600);

 for (fadeValue = 0 ; fadeValue >= 255; fadeValue += 1)
 {for (pin = 1 ; pin <= 12; pin += 1)
 {
  analogWrite(pin, fadeValue);
}delay(150);
}}

// the loop function runs over and over again forever
void loop() {

fadeValue = random(150,255);
//fadeVavue += 50;
pause = random (300,700);
Serial.println("fadeValue:");
Serial.println(fadeValue); 
Serial.println("pause:"); 
Serial.println(pause); 

 for (pin = 1 ; pin <= 12; pin += 1)
{analogWrite(pin, fadeValue);}
delay(pause);
/*
fadeValue = 250;
  Serial.println(fadeValue); 
  for (pin = 1 ; pin <= 12; pin += 1)
{analogWrite(pin, fadeValue);
delay(30);
//Serial.println(pin); 
}
delay(1300);

fadeValue = 150;
  Serial.println(fadeValue); 
  for (pin = 1 ; pin <= 12; pin += 1)
{analogWrite(pin, fadeValue);}
delay(900);


fadeValue = 100;
  Serial.println(fadeValue); 
  for (pin = 1 ; pin <= 12; pin += 1)
{analogWrite(pin, fadeValue);}
delay(800);
  */
}
