/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */


#include <IRremote.h>

IRsend irsend;

void setup()
{
}

void loop() {
	for (int i = 0; i < 3; i++) {
 
 // 1897728D - help
 // 5EDAF50 - luna
 // 202F00F - mute redbox
//  202B04F - ok redbox
// 202D827 - f1
// 20228D7 - f2
// 20230CF - f3
// 20222DD - f4

 //  irsend.sendNEC(0x5ED9768, 32); // - люстра вкл
 //  delay(100);

   irsend.sendNEC(0x1897728D, 32); // - help
   delay(10000);
	}
	delay(400); //5 second delay between each signal burst
}
