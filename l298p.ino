int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;
int Snd = 4;

void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(Snd, OUTPUT);
}

void loop()
{

beep(500);  
vpered();

beep(1000);
nazad();

beep(500); 
beep(500); 
vlevo();

beep(500); 
beep(500); 
beep(500); 
vpravo();

} 
void beep(int drtn)
{
      digitalWrite(Snd,HIGH);
      delay(drtn);
      digitalWrite(Snd,LOW);  
      delay(500); 
}
void vlevo() {
  // разворот влево
 
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,LOW);
      digitalWrite(M2, LOW);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    delay(1000);
}
void vpravo()
 {
  // разворот вправо
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,HIGH);
      digitalWrite(M2, HIGH);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    delay(1000);
  }

  void vpered() {
// вперед
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,HIGH);
      digitalWrite(M2, LOW);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    delay(1000);
  }
  void nazad()
  {
// назад

    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,LOW);
      digitalWrite(M2, HIGH);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    delay(1000);
  }
  

