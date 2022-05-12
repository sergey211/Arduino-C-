const int TIMEOUT_TIME_MS = 150;
unsigned long lastPilotSymbolTime;
char symbol;

int IN1 = 7; // Input1 подключен к выводу 5 
int IN2 = 6;
int IN3 = 5;
int IN4 = 4;
int EN1 = 9;
int EN2 = 3;
int HORN = 11;
int LED = 13;
int val;
int j=100;

enum States
{
  WAITING,
  READING,
  RUNNING,
  ERROR,
  TIMEOUT
};

States state;
States onWait();
States onRead();
States onRun();
States onError();

States onTimeout();

void setup()
{
  Serial.begin(9600);
  lastPilotSymbolTime = 0;
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //используем 13 пин как индикатор включённой ардуины
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
}

void loop()
{
  switch (state)
  {
  case WAITING:
    state = onWait();
    break;
  case READING:
    state = onRead();
    break;
  case RUNNING:
    state = onRun();
    break;
  case TIMEOUT:
    state = onTimeout();
    break;
  default:
    state = onError();
  }
}

States onWait()
{
  if (Serial.available() > 0)
  {
    return READING;
  }
  if (lastPilotSymbolTime && (millis() - lastPilotSymbolTime > TIMEOUT_TIME_MS))
  {
    return TIMEOUT;
  }
  return WAITING;
}

States onRead()
{
  symbol = Serial.read();
  return RUNNING;
}

States onRun()
{
  switch (symbol)
  {

    case '0':
    j=0;
     case '1':
    j=30;
     case '2':
    j=55;
     case '3':
    j=80;
     case '4':
    j=105;
     case '5':
    j=130;
     case '6':
    j=155;
     case '7':
    j=180;
     case '8':
    j=205;
     case '9':
    j=230;
     case 'q':
    j=255;

      case 'W':
    //начало действий при полученном символе 'W' (вперед)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
    pinMode(LED, OUTPUT);
    digitalWrite(LED, HIGH);
    break;

         case 'w':
    //начало действий при полученном символе 'W' (вперед)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    break;

     case 'V':
    //начало действий при полученном символе 'W' (вперед)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
    pinMode(HORN, OUTPUT);
   tone (HORN, 500); //включаем на 500 Гц
delay(100); //ждем 100 Мс
tone(HORN, 1000); //включаем на 1000 Гц
delay(100); //ждем 100 Мс

    break;

    case 'v':
    //начало действий при полученном символе 'W' (вперед)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
    pinMode(HORN, OUTPUT);
    digitalWrite(HORN, LOW);
    break;
    
  case 'F':
    //начало действий при полученном символе 'W' (вперед)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
      analogWrite(EN1, j);
        analogWrite(EN2, j);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;
  case 'B':
    //начало действий при полученном символе 'S' (назад)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
          analogWrite(EN1, j);
        analogWrite(EN2, j);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    break;
  case 'L':
    //начало действий при полученном символе 'D' (вправо)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ] 
          analogWrite(EN1, j);
        analogWrite(EN2, j);
    digitalWrite(IN1, HIGH); // правый
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    break;
  case 'R':
    //начало действий при полученном символе 'A' (влево)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
          analogWrite(EN1, j);
        analogWrite(EN2, j);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    break;
  case 'S':
    //начало действий при полученном символе 'T' (остановка)
    //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
          analogWrite(EN1, j);
        analogWrite(EN2, j);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    break;
  case 'P':
    //получили контрольный символ, не изменяйте этот код
    lastPilotSymbolTime = millis();
    break;
  default:
    return ERROR;
  }
  return WAITING;
}

States onError()
{
  //Получены неоговоренные символы. Очищаем ввод и продолжаем.
  //Здесь можно добавить какие-то действия для этой ситуации.
  //...
  while (Serial.available())
  {
    Serial.read();
  }
  return WAITING;
}

States onTimeout()
{
  //Действия при таймауте.
  //Вероятно, связь утеряна,
  //но при получении контрольного символа она будет восстановлена.
  //Здесь, например, уместно выключить двигатели
  //[ДОБАВИТЬ СВОЙ КОД НИЖЕ]
  digitalWrite(IN1, LOW); // На пары выводов IN поданы сигналы одинакового уровня, моторы не работают
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  if (Serial.available())
  {
    return READING;
  }
  return TIMEOUT;
}
