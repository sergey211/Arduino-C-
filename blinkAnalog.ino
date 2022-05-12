int led3 = 3; 
int led5 = 4; 
int led6 = 5;
int led9 = 6;
int led10 = 7;
int led11 = 8;
int led4d = 2;
int led12d = 9;

/* int led3 = 3; 
int led5 = 5; 
int led6 = 6;
int led9 = 9;
int led10 = 10;
int led11 = 11;
*/

int but2 = 10; //2  
     
//int led4d = 4;
//int led12d = 12;

int pause;
int mode = 0;

// 3,5,6,9,10 и 11
 
void setup()
{
    pinMode(led3, OUTPUT);  
    pinMode(led5, OUTPUT);     
    pinMode(led6, OUTPUT);     
    pinMode(led9, OUTPUT);     
    pinMode(led10, OUTPUT);     
    pinMode(led11, OUTPUT);     
    pinMode(led4d, OUTPUT);     
    pinMode(led12d, OUTPUT);     
    pinMode(but2, INPUT);
    Serial.begin(9600);     
}
 
void loop()
{
  Serial.print("mode = ");
  Serial.println(mode);
  delay(500);
  int button;
//  digitalRead(but2) = button;
  Serial.print("button = ");
  Serial.println(digitalRead(but2));
  
  if (digitalRead(but2) == 1) // 1 - если кнопка нажата  
  {
    mode++;
  }
  
if (mode>3)
  {
  mode=0;
  }

switch (mode) {

      case 0: // горят от центра к краю

  pause = 100;
  digitalWrite(led4d, LOW); 
  digitalWrite(led12d, LOW);
    digitalWrite(led3, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW); 

 digitalWrite(led6, HIGH); 
  digitalWrite(led9, HIGH); 
  delay(pause);  
  digitalWrite(led6, LOW); 
    digitalWrite(led9, LOW); 
  
digitalWrite(led10, HIGH); 
  digitalWrite(led5, HIGH); 
  delay(pause);  
  digitalWrite(led10, LOW); 
    digitalWrite(led5, LOW);

    digitalWrite(led11, HIGH); 
  digitalWrite(led3, HIGH); 
  delay(pause);  
  digitalWrite(led11, LOW); 
    digitalWrite(led3, LOW);
  
digitalWrite(led4d, HIGH); 
  digitalWrite(led12d, HIGH); 
  delay(pause);  
  digitalWrite(led4d, LOW); 
    digitalWrite(led12d, LOW);

       break;

  
    case 1:  // диоды бегают
  pause = 100;
  digitalWrite(led4d, LOW); 
  digitalWrite(led12d, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW); 

 digitalWrite(led4d, HIGH); 
  delay(pause);  
  digitalWrite(led4d, LOW); 
  
  digitalWrite(led3, HIGH); 
  delay(pause);  
  digitalWrite(led3, LOW); 
  
  digitalWrite(led5, HIGH); 
  delay(pause);  
  digitalWrite(led5, LOW); 

  digitalWrite(led6, HIGH); 
  delay(pause);  
  digitalWrite(led6, LOW); 
   
  
  digitalWrite(led9, HIGH); 
  delay(pause);  
  digitalWrite(led9, LOW); 

  digitalWrite(led10, HIGH); 
  delay(pause);  
  digitalWrite(led10, LOW); 
  
  digitalWrite(led11, HIGH); 
  delay(pause);  
  digitalWrite(led11, LOW); 
  
  digitalWrite(led12d, HIGH); 
  delay(pause);  
  digitalWrite(led12d, LOW);
     
      break;

       
    case 2:  // все диоды просто горят
  digitalWrite(led3, HIGH); 
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led4d, HIGH);
  digitalWrite(led12d, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  digitalWrite(led11, HIGH);    
      break;


       case 3: // выключено
  digitalWrite(led3, LOW); 
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led4d, LOW);
  digitalWrite(led12d, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  digitalWrite(led11, LOW); 
     

       break;


/*           case 4: // яркость
      pause = 4;
       for (int brightness = 0; brightness <= 255; brightness++) {
  
      analogWrite(led3, brightness);
      analogWrite(led5, brightness);
      analogWrite(led6, brightness);
      analogWrite(led9, brightness);
      analogWrite(led10, brightness);
      analogWrite(led11, brightness);

      
   
      delay(pause);
    }

//digitalWrite(led4d, HIGH);
//digitalWrite(led12d, HIGH);

delay(1000);

//digitalWrite(led4d, LOW);
//digitalWrite(led12d, LOW);
 for (int brightness = 255; brightness >= 0; brightness--) {
  
      analogWrite(led3, brightness);
      analogWrite(led5, brightness);
      analogWrite(led6, brightness);
      analogWrite(led9, brightness);
      analogWrite(led10, brightness);
      analogWrite(led11, brightness);
      
      delay(pause);
    }
     

      break;

       case 5:  // яркость 
      pause = 6;
      for (int brightness = 0; brightness <= 255; brightness++) {
      analogWrite(led6, brightness);
      analogWrite(led9, brightness);
      delay(pause);
    }

     for (int brightness = 0; brightness <= 255; brightness++) {
     analogWrite(led5, brightness);
     analogWrite(led10, brightness);
     delay(pause);
    }

     for (int brightness = 0; brightness <= 255; brightness++) {
     analogWrite(led3, brightness);
     analogWrite(led11, brightness);
     delay(pause);
    }
    delay(500);
//    digitalWrite(led4d, HIGH);
//    digitalWrite(led12d, HIGH);


       for (int brightness = 255; brightness >=0 ; brightness--) {
      analogWrite(led6, brightness);
      analogWrite(led9, brightness);
      delay(pause);
    }

    for (int brightness = 255; brightness >=0 ; brightness--) {
     analogWrite(led5, brightness);
     analogWrite(led10, brightness);
     delay(pause);
    }

    for (int brightness = 255; brightness >=0 ; brightness--) {
     analogWrite(led3, brightness);
     analogWrite(led11, brightness);
     delay(pause);
    }
 //   delay(1000);
 //   digitalWrite(led4d, LOW);
 //   digitalWrite(led12d, LOW);

 
       break;

*/

      //  default:
      // выполняется, если не выбрана ни одна альтернатива
      // default необязателен
  }
}
  
 /*     for (int brightness = 0; brightness < 255; brightness++) {
      analogWrite(Pin7, brightness);
      delay(6);
      }
  analogWrite(analogLed0, 255);   // turn the LED on (HIGH is the voltage level)
 analogWrite(analogLed5, 255);
 analogWrite(analogLed6, 255);
  digitalWrite(Led, HIGH); 
  delay(1000);                       // wait for a second
  analogWrite(analogLed0, 0);    // turn the LED off by making the voltage LOW
  analogWrite(analogLed5, 0); 
  analogWrite(analogLed6, 0); 
  digitalWrite(Led, LOW); 
//     for (int brightness = 255; brightness >= 0; brightness--) {
//      analogWrite(Pin7, brightness);
      delay(6);
    }
  delay(1000); 
 // analogWrite(ledPin, val / 4); // analogRead возвращает значения от 0 до 1023, analogWrite должно быть в диапозоне от 0 до 255
}*/

