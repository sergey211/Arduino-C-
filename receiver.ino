#include <RemoteReceiver.h>
// пин 2.это вход для Радиоприёмника
void setup() {
Serial.begin(9600);
RemoteReceiver::init(0, 3, showCode);
}
void loop() {
}
void showCode(unsigned long receivedCode, unsigned int period) {
Serial.print("Code: ");
Serial.print(receivedCode);
Serial.print(", period duration: ");
Serial.print(period);
Serial.println("us.");
}
