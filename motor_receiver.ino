#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
int Steps = 0;
boolean Direction = true;
unsigned long last_time;
unsigned long currentMillis ;
int steps_left=1500;
long time;
#include <RemoteReceiver.h>
// пин 2.это вход для Радиоприёмника
const int stepsPerRevolution = 200;
void setup() {

Serial.begin(115200);
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);
RemoteReceiver::init(0, 3, showCode);

}

void loop() {
//steps_left=1500;
 }
  void showCode(unsigned long receivedCode, unsigned int period) 
  {
Serial.print("Code: ");
Serial.print(receivedCode);
Serial.print(", period duration: ");
Serial.print(period);
Serial.println("us.");

if (receivedCode==615363)
{


//Функция ожидает, пока поступит команда, преобразовывает текст и подает сигнал на двигатель для его вращения на указанное число шагов.
Serial.println("Move right"); //по часовой стрелке
while(steps_left>0)
  {
currentMillis = micros();
if(currentMillis-last_time>=1000)
    {
stepper(1);
time=time+micros()-last_time;
last_time=micros();
steps_left--;
    }
  }
}


else if (receivedCode==615366)
  {
    Serial.println("left!");
//delay(2000);

Serial.println("Move left"); //против часовой стрелки
Serial.println(time);
Serial.println("Wait...!");
//delay(2000);
Serial.println("Move right"); //по часовой стрелке
Direction=!Direction;

while(steps_left<1500)
    {
currentMillis = micros();
if(currentMillis-last_time>=1000)
      {
stepper(1);
time=time+micros()-last_time;
last_time=micros();
steps_left++;

     }
   }
   Direction=!Direction;

  

   // */ // 615366
  } 
  
}
void stepper(int xw){
for (int x=0;x<xw;x++){
switch(Steps){
case 0:
digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
break;

case 1:

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, HIGH);

break;

case 2:

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

break;

case 3:

digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);

break;

case 4:

digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

break;

case 5:

digitalWrite(IN1, HIGH);
digitalWrite(IN2, HIGH);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

break;

case 6:

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

break;

case 7:

digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);

break;

default:

digitalWrite(IN1, LOW);
digitalWrite(IN2, LOW);
digitalWrite(IN3, LOW);
digitalWrite(IN4, LOW);

break;

}

SetDirection();

}

}

void SetDirection(){

if(Direction==1){ Steps++;}
if(Direction==0){ Steps--; }
if(Steps>7){Steps=0;}
if(Steps<0){Steps=7; }

}

