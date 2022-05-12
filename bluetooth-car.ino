
// Тестировалось на Arduino IDE 1.0.5
int IN1 = 10; // Input1 подключен к выводу 5 
int IN2 = 11;
int IN3 = 12;
int IN4 = 13;
char btCommand = 'S';

void setup()
{
  Serial.begin (9600); 
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
}
// вперед
void forward (int a) // ВПЕРЕД
 { digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); // правое ВПЕРЕД
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // левое вперед
  delay(50*a);
}
void back (int g) // НАЗАД
  // назад
{
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); // правое назад
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); // левое назад
  delay(50*g);
}  
// налево
void left (int c) // ПОВОРОТ ВЛЕВО
{
 digitalWrite (IN2, HIGH); // поменял
    digitalWrite (IN1, LOW); // правое ВПЕРЕД поменял
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW); // левое стоп

  
  delay(50*c);
  }
// направо
void right (int b) // ПОВОРОТ ВПРАВО (одна сторона)
{
   

    digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое стоп
  digitalWrite (IN4, HIGH); // поменял
  digitalWrite (IN3, LOW); // левое вперед поменял
  
  delay(50*b);
  }
// стоп
void stop (int f) // СТОП
{
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое стоп
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW); // левое стоп
  delay(50*f);
}
void loop()

{
if (Serial.available() > 0)// В случае если в "Серийном порту"
//есть информация
{
btCommand = Serial.read(); // Считываем инвормацию с
//"Серийного порта"
Serial.println(btCommand); // Печатаем инвормацию с
//"Серийного порта" — необходио в слуае отладки программы

switch (btCommand) // Отрабатывем в соотвествии с
//поступившей командой
{
case 'F':
forward (3); // едем ВПЕРЕД
break;
case 'B':
back (3); // едем НАЗАД
break;
case 'R':
right (3); // поворачиваем ВПРАВО
break;
case 'L':
left (3); // поворачиваем ВЛЕВО
break;
case 'S':
stop (3); // СТОП!
} } }



