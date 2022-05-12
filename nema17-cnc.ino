const int dirPin = 5; // x dir 
const int stepPin = 2; // x step
const int enPin = 8; // x step

const int dirPinY = 6; // y dir 
const int stepPinY = 3; // y step

const int dirPinZ = 7; // z dir 
const int stepPinZ = 4; // z step


const int stepsPerRevolution = 200;
 
void setup()
{
  pinMode(stepPin, OUTPUT);
    pinMode(enPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
    pinMode(stepPinY, OUTPUT);
  pinMode(dirPinY, OUTPUT);
    pinMode(stepPinZ, OUTPUT);
  pinMode(dirPinZ, OUTPUT);
}
void loop()
{
   digitalWrite(enPin, LOW); 
  digitalWrite(dirPin, HIGH); // Установка вращения по часовой стрелки
   digitalWrite(dirPinY, HIGH); 
    digitalWrite(dirPinZ, HIGH); 
    
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
     digitalWrite(stepPinY, HIGH);
      digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
     digitalWrite(stepPinY, LOW);
      digitalWrite(stepPinZ, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);
  
  digitalWrite(dirPin, LOW); // Установка вращения против часовой стрелки
  digitalWrite(dirPinY, LOW); 
   digitalWrite(dirPinZ, LOW); 
   
  for(int x = 0; x < stepsPerRevolution; x++)
  {
    digitalWrite(stepPin, HIGH);
     digitalWrite(stepPinY, HIGH);
      digitalWrite(stepPinZ, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
     digitalWrite(stepPinY, LOW);
      digitalWrite(stepPinZ, LOW);
    delayMicroseconds(2000);
  }
  delay(1000);
}
