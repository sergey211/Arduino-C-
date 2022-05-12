#include <SoftwareSerial.h>
 
SoftwareSerial gprsSerial(4, 5);
 
int btnPin = 12;
boolean prevBtn = LOW;
 
void setup()
{
    gprsSerial.begin(19200);
}
 
void loop()
{
     {
        //сразу после нажатия кнопки начинаем звонить по заданному номеру
        gprsSerial.println("ATD + +375336621228;");
    }
//    prevBtn = currBtn;
}
