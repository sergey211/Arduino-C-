//tv - "samsung aa59-0038a" amp - yamaha rav16
//tv volume up    0xE0E0E01F 
//tv volume down  0XE0E0D02F
//tv off/on       0xE0E040BF
//amp volume up   0x5EA158A7
//amp volume down 0x5EA1D827
//amp off/on      0x5EA1F807

#include <IRremote.h>
#define irPin 2
#define irSendPin 3
IRrecv irrecv(irPin);
IRsend irsend;  

decode_results results;

void setup() {
   Serial.begin(9600);
   pinMode(irSendPin, OUTPUT); 
   irrecv.enableIRIn();
   //irsend.enableIROut(38);
   //irsend.mark(0);
}
void loop() {
   if (irrecv.decode(&results)) {
   
   delay(1); 
   
            switch(results.value) {
        
            case 0x202F00F: // mute
            Serial.println(results.value, HEX);
            irsend.sendNEC(0x1897728D, 32); //help
            delay(80);
            Serial.println("send help 10 sec, mute");
            break;
                  
            case 0x5EDAF50: // luna
            Serial.println(results.value, HEX);
              for (int i = 0; i < 220; i++) {
              irsend.sendNEC(0x1897728D, 32); // - help
              delay(80);}
            Serial.println("send help 220 times, luna");
            break;
        
            case 0x202B04F: // ok redbox
            Serial.println(results.value, HEX);
              for (int i = 0; i < 2; i++) {
              irsend.sendNEC(0x5ED9768, 32); // - lamp
              delay(80);}
              Serial.println("send lamp on/off - ok");
            break;     

          // вот рабочий код:  
            case 0x202D827: // f1 redbox
            Serial.println(results.value, HEX);
              for (int i = 0; i < 2; i++) {
              irsend.sendNEC(0x1897728D, 32); // - help
              delay(80);}
              Serial.println("send help - f1");
            break;

            
      }       
        
   irrecv.resume();
   irrecv.enableIRIn();
   }
}
