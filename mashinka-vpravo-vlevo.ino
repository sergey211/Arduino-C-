// Тестировалось на Arduino IDE 1.0.5
int IN1 = 10; // Input1 подключен к выводу 5 
int IN2 = 11;
int IN3 = 12;
int IN4 = 13;
int EN1 = 9;
int EN2 = 3;
int i;
void setup()
{
  pinMode (EN1, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (EN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
}
void loop()
{ //перед это плата - круто влево
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое назад
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // девое вперед
  for (i = 50; i <= 180; ++i)
  {
      analogWrite(EN1, i);
      analogWrite(EN2, i);
      delay(30);
  }
  analogWrite (EN1, 0);
  analogWrite (EN2, 0);
  delay(500);
      // круто вправо
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); // правое вперед
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); // левое назад
  for (i = 50; i <= 180; ++i)
  {
      analogWrite(EN1, i);
      analogWrite(EN2, i);
      delay(30);
  }
  analogWrite (EN1, 0);
  analogWrite (EN2, 0);
  delay(8000);
}
