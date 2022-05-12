#include <Servo.h>
Servo myservo1;
Servo myservo2;

const int dirPin = 5; // x dir 
const int stepPin = 2; // x step
const int enPin = 8; // enable

const int dirPinY = 6; // y dir 
const int stepPinY = 3; // y step

const int dirPinZ = 7; // z dir 
const int stepPinZ = 4; // z step


 int dirPinA; // a dir 
 int stepPinA; // a step

#define pinX    A2  // ось X джойстика RED - RESUME
#define pinY    A1  // ось Y джойстика BLUE - HOLD
#define swPin    13  // кнопка джойстика SPN dir



const int stepsPerRevolution = 100;
const int delaymc = 500;
int counter = 1;
 
void setup()
{

  Serial.begin(9600);
  myservo1.attach(9); // x pin cnc
  myservo2.attach(10); // y pin cnc
//  pinMode(ledPin, OUTPUT);
  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  
  pinMode(swPin, INPUT);
 // digitalWrite(swPin, HIGH);
  
  pinMode(stepPin, OUTPUT);
  pinMode(enPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
  pinMode(stepPinZ, OUTPUT);
  pinMode(dirPinZ, OUTPUT);

  pinMode(stepPinA, OUTPUT);
  pinMode(dirPinA, OUTPUT);
}
void loop()
{
 
 //boolean ledState = digitalRead(swPin); 
/* if 

( digitalRead(swPin)==true)

{
  
   for(int x = 0; x < 2000; x++)
  {

 //  digitalWrite(enPin, LOW); 
   digitalWrite(dirPinZ, HIGH); // Установка вращения по часовой стрелки
   digitalWrite(stepPinZ, HIGH);
   delayMicroseconds(delaymc);
   digitalWrite(stepPinZ, LOW);
   delayMicroseconds(500);
  }
    
  
   
  for(int x = 0; x < 2000; x++)
  {
    digitalWrite(dirPinZ, LOW); // Установка вращения против часовой стрелки
    digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(delaymc);
    digitalWrite(stepPinZ, LOW);
    delayMicroseconds(500);
  }
  
  
  }
  */

/*
else {counter=counter+1;
}

if ((counter % 2)==0)
{  stepPinA = stepPinZ;
   dirPinA = dirPinZ; }
else 
{  stepPinA = stepPinY;
   dirPinA = dirPinY; }

*/

   stepPinA = stepPinY;
   dirPinA = dirPinY;

  int joyX = analogRead(pinX);              // считываем значение оси Х
  int joyY = analogRead(pinY);              // считываем значение оси Y

  Serial.print(joyX);                       // выводим в Serial Monitor
  Serial.print("\t");                    // табуляция
  Serial.println(joyY);
  Serial.print("\t");                    // табуляция
  Serial.println(counter);
 // delay(1000);  // for debug counter
    if (joyX>1000)
    {
       myservo1.write(30); // x pin 
  for(int x = 0; x < stepsPerRevolution; x++)
  {

   digitalWrite(enPin, LOW); 
   digitalWrite(dirPin, HIGH); // Установка вращения по часовой стрелки
   digitalWrite(stepPin, HIGH);
   delayMicroseconds(delaymc);
   digitalWrite(stepPin, LOW);
   delayMicroseconds(delaymc);
  }
    }
  
    if (joyX<25)
    {
      myservo1.write(150);

  for(int x = 0; x < stepsPerRevolution; x++)
  {
   digitalWrite(enPin, LOW); 
   digitalWrite(dirPin, LOW); // Установка вращения против часовой стрелки
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(delaymc);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(delaymc);
  }
    }



   if (joyY>1000)
    {
      myservo2.write(0);
  for(int x = 0; x < stepsPerRevolution; x++)
  {

   digitalWrite(enPin, LOW); 
   digitalWrite(dirPinA, HIGH); // Установка вращения по часовой стрелки
   digitalWrite(stepPinA, HIGH);
   delayMicroseconds(delaymc);
   digitalWrite(stepPinA, LOW);
   delayMicroseconds(delaymc);
  }
    }
  
    if (joyY<25)
    { myservo2.write(180);
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(enPin, LOW); 
    digitalWrite(dirPinA, LOW); // Установка вращения против часовой стрелки
    digitalWrite(stepPinA, HIGH);
    delayMicroseconds(delaymc);
    digitalWrite(stepPinA, LOW);
    delayMicroseconds(delaymc);
  }
    }

    
    
}
