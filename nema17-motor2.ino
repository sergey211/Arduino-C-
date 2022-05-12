/*Программа для вращения шагового мотора NEMA 17, серии 17HS4402 + драйвер A4988. В программе попеременно сменяются режимы шага: полношаговый, 1/2, 1/4, 1/8, 1/16 шага, при каждом из них мотор совершает оборот на 200 шагов в одну сторону, потом в другую*/
/*целочисленная константа, хранящая номер цифрового контакта Arduino, который подаёт сигнал Step на драйвер. Каждый импульс от этого контакта — это перемещение мотора на один шаг*/
const int pinStep = 5;
/*целочисленная константа, хранящая номер цифрового контакта Arduino, который подаёт сигнал Direction на драйвер. Наличие импульса - мотор вращается в одну сторону, отсутствие - в другую*/
const int pinDir = 4;

//временная задержка между шагами мотора в мс
const int move_delay = 4;

//шагов на полный оборот
const int steps_rotate_360 = 3600; // 200

/*контакты на драйвере, задающие режим шага мотора - MS1, MS2, MS3*/
int StepModePins[3] = {8, 7, 6};

//размер массива StepModePins
const int StepModePinsCount = 3;

/*Массив, хранящий состояния контактов MS1, MS2, MS3 драйвера, при которых задаются разные режимы вращения: полношаговый, 1/2, 1/4, 1/8, 1/16я шага*/
bool StepMode[5][3] = {
  { 0, 0, 0},
  { 1, 0, 0},
  { 0, 1, 0},
  { 1, 1, 0},
  { 1, 1, 1} };

//размер массива StepMode
const int StepModeSize = 5;

/*Функция, в которой происходит инициализация всех переменных программы*/
void setup()
{

  Serial.begin(9600);
/*задаём контактам Step и Direction режим вывода, то есть они выдают напряжение*/
  pinMode(pinStep, OUTPUT);
  pinMode(pinDir, OUTPUT);

  for(int i = 0; i < StepModePinsCount; i++)
  {
    pinMode(StepModePins[i], OUTPUT);
  }

//устанавливаем начальный режим
  digitalWrite(pinStep, HIGH);
  digitalWrite(pinDir, LOW);
}

/*Функция-цикл в которой задаётся поведение программы*/
void loop()

{

//  digitalWrite(StepModePins[2], StepMode[4][2] == 1 ? HIGH : LOW);
// digitalWrite(StepModePins[j], StepMode[i][j] == 1 ? HIGH : LOW);
{
  for(int i = 4; i < StepModeSize; i++) //i=0
  {
    for(int j = 0; j < StepModePinsCount; j++)
    {
      digitalWrite(StepModePins[j], StepMode[i][j] == 1 ? HIGH : LOW);
      Serial.print("i=");
      Serial.print(i);
      Serial.print(",j=");
      Serial.println(j);
    }

//вращаем мотор в одну сторону, затем в другую
    MakeRoundRotation();
  }}
  
}

/*функция, в которой мотор совершает 200 шагов в одном направлении, затем 200 в обратном*/
void MakeRoundRotation()
{
//устанавливаем направление вращения
  digitalWrite(pinDir, HIGH);

  for(int i = 0; i < steps_rotate_360; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(move_delay);
    digitalWrite(pinStep, LOW);
    delay(move_delay);
  }

  delay(move_delay*10);

//устанавливаем направление вращения обратное
 /* digitalWrite(pinDir, LOW);

  for(int i = 0; i < steps_rotate_360; i++)
  {
    digitalWrite(pinStep, HIGH);
    delay(move_delay);
    digitalWrite(pinStep, LOW);
    delay(move_delay);
  }

  delay(move_delay*10);
  */
}
