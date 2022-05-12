#include <IRremote.h>
#include <IRremoteInt.h>
IRsend irsend;

IRrecv irrecv(8);
decode_results results;
int re = 0;
void setup() {
 
  Serial.begin(9600);   
  irrecv.enableIRIn();    
}

void loop() {
 if(re == 1){
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
unsigned int irSignal[] = {12900,600,2100,550,750,1900,800,1900,750}; //AnalysIR Batch Export (IRremote) - RAW
irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
re = 0;
irrecv.enableIRIn();
 };

   if ( irrecv.decode( &results )) { 
    Serial.println(results.value, HEX);
        //             5ED9768
if (results.value==0x5ED9768){//5
re=1;
}; 
 results.value=0;
     irrecv.resume();  
}; 

}
