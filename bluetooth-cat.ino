// Тестировалось на Arduino IDE 1.0.5
int IN1 = 10; // Input1 подключен к выводу 10
int IN2 = 11;
int IN3 = 12;
int IN4 = 13;

int f1 = 7;
int f2 = 6;
int f3 = 5;
int f4 = 4;

int buttonState = 0;

void setup()
{
  Serial.begin(9600);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);

  pinMode (f1, INPUT);
  pinMode (f2, INPUT);
  pinMode (f3, INPUT);
  pinMode (f4, INPUT);
  Serial.println("srart");
}
void loop()

{


  
buttonState = digitalRead(f1);  
if (buttonState==LOW)

{Serial.println("f1 = 0");// левая крайняя фара видит барьер
// значит поворачиваем направо
  // направо
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH); // правое НАЗАД
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // левое вперед
  delay(300);

}

buttonState = digitalRead(f4);  
if (buttonState==LOW)
 {Serial.println("f4 = 0");
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое стоп
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); // левое НАЗАД
delay(300);}

buttonState = digitalRead(f2);  
if (buttonState==LOW)

{Serial.println("f2 = 0");

  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); // правое назад
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW); // левое стоп
delay(300);
}
buttonState = digitalRead(f3);  
if (buttonState==LOW)
{Serial.println("f3 = 0");
// повернем налево
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); // правое ВПЕРЕД
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); // левое стоп
  delay(300);
}


else
 { digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); // правое ВПЕРЕД
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // левое вперед
  delay(300);
 }
delay(10);
}
/*
{ // вперед
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); // правое ВПЕРЕД
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // левое вперед
  delay(1000);


  
  // назад
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW); // правое назад
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW); // левое назад
  delay(3000);
  // налево
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); // правое ВПЕРЕД
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW); // левое стоп
  delay(1000);
  // направо
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое стоп
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); // левое вперед
  delay(1000);
  // стоп
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, LOW); // правое стоп
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW); // левое стоп
  delay(1000);
}

*/
