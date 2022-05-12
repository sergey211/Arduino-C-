#include <IRremote.h> // подключаем библиотеку
 
int ledPin = 13; // светодиод
int reciverPin = 11; // пин, к котрому подключен ИК-приемник
IRrecv irrecv(reciverPin);
  
decode_results results;
  
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // запуск приемника
  pinMode(ledPin, OUTPUT);
}
  
void loop() {
  // постоянно считываем данные с приемника
  if (irrecv.decode(&results)) {
    // выводим в консольку, что получили, число в 16-ричном виде
    Serial.println(results.value, HEX);
    // проверяем сигналы - и если это те, что нам нужны, то вкл или выкл светодиод
    if(results.value == 0x926DC837) digitalWrite(13, HIGH);
    if(results.value == 0x926D48B7) digitalWrite(13, LOW);
    irrecv.resume(); // готовы принимать следующий сигнал
  }
}
