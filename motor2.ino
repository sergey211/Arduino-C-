#include <Stepper.h>
const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 8,9,10,11); //подключение к пинам 8…11 на Ардуино
void setup() {
myStepper.setSpeed(60); //установка скорости вращения ротора
Serial.begin(9600);
}

void loop() {
//Функция ожидает, пока поступит команда, преобразовывает текст и подает сигнал на двигатель для его вращения на указанное число шагов.
Serial.println("Move right"); //по часовой стрелке
myStepper.step(stepsPerRevolution);
delay(1000);
Serial.println("Move left"); //против часовой стрелки
myStepper.step(-stepsPerRevolution);
delay(1000);
}
