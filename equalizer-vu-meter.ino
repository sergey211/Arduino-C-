
//Led VU Meter Example

// Version 1.0
// Written by James Newbould
// Edited a little by Zero the Geek 08-13-2013

int led[10] = { 3,4,5,6,9,10,11,12 }; // Assign the pins for the leds
int leftChannel = 0;  // left channel input
int left, i;
void setup()

{

for (i = 0; i < 10; i++)  // Tell the arduino that the leds are digital outputs
pinMode(led, OUTPUT);
//Serial.begin(9600); // Uncomment to enable troubleshooting over serial.

}

void loop()

{

left = analogRead(leftChannel);  // read the left channel

// Serial.println(left);  // uncomment to check the raw input.

left = left / 50 ;    // adjusts the sensitivity *edit My sensitivity is low because my phone does not have a good amplifier bulit in.

//  Serial.println(left);  // uncomment to check the modified input.

// left = 1500;  // uncomment to test all leds light.

 //left = 0;    // uncomment to check the leds are not lit when the input is 0.

  if (left == 0)  // if the volume is 0 then turn off all leds
   {
   for(i = 0; i < 10; i++)
     {
     digitalWrite(led, LOW);
     }
  }
  else
  {
   for (i = 0; i < left; i++) // turn on the leds up to the volume level
    {
     digitalWrite(led, HIGH);
    }
    for(i = i; i < 10; i++)  // turn off the leds above the voltage level
     {
      digitalWrite(led, LOW);
     }
  }
}

