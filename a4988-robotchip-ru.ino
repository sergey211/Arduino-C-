/* 
 *  Тестировалось на Arduino IDE 1.8.5
 *  Дата тестирования 19.12.2018г.
*/
const int dirPin = 12;
const int stepPin = 13;
const int stepsPerRevolution = 200;
 
void setup()
{
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop()
{
  digitalWrite(dirPin, HIGH); // Установка вращения по часовой стрелки
   
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);
   
  digitalWrite(dirPin, LOW); // Установка вращения против часовой стрелки
 
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(1000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(1000);
  }
  delay(1000);
}
