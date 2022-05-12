int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;
int Snd = 4;
int RtRed = 5;
int RtBlu = 6;
int RtGrn = 2;
int LtRed = 8;
int LtBlu = 3;
int LtGrn = 7;
int LtGus = A4;
int RtGus = A5;

void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(Snd, OUTPUT);
  
  pinMode(RtRed, OUTPUT);
  pinMode(RtBlu, OUTPUT);
  pinMode(RtGrn, OUTPUT);
  pinMode(LtRed, OUTPUT);
  pinMode(LtBlu, OUTPUT);
  pinMode(LtGrn, OUTPUT);
  
  pinMode(RtGus, OUTPUT);
  pinMode(LtGus, OUTPUT);
  
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

      digitalWrite(RtBlu,HIGH);
      digitalWrite(LtBlu,HIGH);
      digitalWrite(Snd,HIGH);
      delay(drtn);
      
      digitalWrite(Snd,LOW);  
      digitalWrite(RtBlu,LOW);
      digitalWrite(LtBlu,LOW);
      delay(500); 
}
void vlevo() {
  // разворот влево
 
// правое назад левое вперед 


      digitalWrite(RtRed, HIGH);
      digitalWrite(LtGrn, LOW);
      digitalWrite(LtGrn, HIGH);

        
      analogWrite(RtGus, 0);
      analogWrite(LtGus, 255);
        
     
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,LOW);
      digitalWrite(M2, LOW);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(1000);
    
      digitalWrite(RtRed,LOW);
      analogWrite(RtGus, 0);
      analogWrite(LtGus, 0);
}
void vpravo()
 {
  // разворот вправо
  // левое назад правое вперед
    int value;

      digitalWrite(LtRed, HIGH);
      analogWrite(RtGus, 255);
      analogWrite(LtGus, 0);
    
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1, HIGH);
      digitalWrite(M2, HIGH);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
  
  
      analogWrite(E1, 0);
      analogWrite(E2, 0);
  
     delay(1000);

      digitalWrite(LtRed, LOW);
      analogWrite(RtGus, 0);
      analogWrite(LtGus, 0);
  }

  void nazad() {

      digitalWrite(RtRed,HIGH);
      digitalWrite(LtRed, HIGH);
      analogWrite(RtGus, 255);
      analogWrite(LtGus, 255);

      
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,HIGH);
      digitalWrite(M2, LOW);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    analogWrite(E1, 0);
      analogWrite(E2, 0);
    delay(1000);

      digitalWrite(RtRed,LOW);
      digitalWrite(LtRed, LOW);
      analogWrite(RtGus, 0);
      analogWrite(LtGus, 0);
  }
  
void vpered()
  {

      digitalWrite(RtGrn,HIGH);
      digitalWrite(LtGrn, HIGH);
      analogWrite(RtGus, 255);
      analogWrite(LtGus, 255);
    
    int value;
    for(value = 0 ; value <= 255; value+=5)
    {
      digitalWrite(M1,LOW);
      digitalWrite(M2, HIGH);
      analogWrite(E1, value);
      analogWrite(E2, value);
      delay(30);
    }
    analogWrite(E1, 0);
      analogWrite(E2, 0);
   
    digitalWrite(RtGrn,LOW);
    digitalWrite(LtGrn, LOW);
  
    analogWrite(RtGus, 0);
    analogWrite(LtGus, 0);
     delay(1000);
  }
  

