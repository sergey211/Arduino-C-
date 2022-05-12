/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */
    
int randNumber;
int rand2;
int var;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
     pinMode(2, OUTPUT);
  pinMode(6, OUTPUT);
  
     Serial.begin(9600);

 
}

// the loop function runs over and over again forever
void loop() {


  randNumber = random(7);
  Serial.println(randNumber); 

  for (int pin = 2 ; pin <= 6; pin +=1 )

  switch (randNumber) {
    case 0:
      //выполняется, когда var равно 0
      // плавно ярче, плавно тускнее
      {
  for (int fadeValue = 200 ; fadeValue >= 255; fadeValue += 5)
  {
  analogWrite(pin, fadeValue);
  analogWrite(pin+2, fadeValue);
  delay(30);
  }
  for (int fadeValue = 255 ; fadeValue <= 200; fadeValue -= 5)
  {
  analogWrite(pin, fadeValue);
   analogWrite(pin+2, fadeValue);
  delay(30);
  }}
      
      break;
    case 1:
   //  плавно тускнее , плавно ярче
 { for (int fadeValue = 200 ; fadeValue <= 0; fadeValue -= 5)
  {
  analogWrite(pin, fadeValue);
  analogWrite(pin+1, fadeValue);
  delay(30);
  }
  for (int fadeValue = 0 ; fadeValue >= 200; fadeValue += 5)
  {
  analogWrite(pin, fadeValue);
    analogWrite(pin+1, fadeValue);
  delay(30);
  }
 } 
      //выполняется когда  var равно 1
      break;
    case 2:
    {
    //выполняется, когда var равно 2
  analogWrite(pin, 220);    
    analogWrite(pin-1, 220);  
  delay(500);  
   analogWrite(pin, 240);    
   analogWrite(pin-1, 240);   
   
  delay(500); 
    analogWrite(pin, 200);    
    analogWrite(pin-1, 200);
  delay(500); 
     analogWrite(pin, 150);    
     analogWrite(pin-1, 150);    
  delay(500); 
      analogWrite(pin, 200);  
       analogWrite(pin-1, 200);    
  delay(500); 
      analogWrite(pin, 150);  
        analogWrite(pin-1, 150);     
  delay(500);   
    }  
      break;
    case 3:
    {
      //выполняется когда  var равно 3
  analogWrite(pin, 200);    
    analogWrite(pin+1, 200); 
  delay(500);  
   analogWrite(pin, 150); 
     analogWrite(pin+1, 150);    
  delay(500); 
    analogWrite(pin, 250); 
      analogWrite(pin+1, 250);    
  delay(500); 
     analogWrite(pin, 200);    
       analogWrite(pin+1, 200);    
  delay(500); 
      analogWrite(pin, 240);    
      analogWrite(pin+1, 240); 
  delay(500); 
      analogWrite(pin, 200);    
      analogWrite(pin+1, 200); 
  delay(500);
    }
      break;
    case 4:
    {
      //выполняется, когда var равно 4
  analogWrite(pin, 220);  
  analogWrite(pin-2, 220);   
  delay(500);  
   analogWrite(pin, 240);
   analogWrite(pin-2, 240);       
  delay(300); 
    analogWrite(pin, 200); 
    analogWrite(pin-2, 200);      
  delay(800); 
     analogWrite(pin, 180); 
     analogWrite(pin-2, 180);      
  delay(2000); 
      analogWrite(pin, 160); 
      analogWrite(pin-2, 160);      
  delay(700); 
      analogWrite(pin, 200);  
      analogWrite(pin-2, 200);     
  delay(900); 

    }
      break;
    case 5:
      //выполняется когда  var равно 5
{
        
 analogWrite(pin, 200);    
  analogWrite(pin+1, 200);   
  analogWrite(pin-1, 200); 
  delay(900);  
   analogWrite(pin, 140);
     analogWrite(pin+1, 140);   
  analogWrite(pin-1, 140); 
    
  delay(300); 
    analogWrite(pin, 220);  
      analogWrite(pin+1, 220);   
  analogWrite(pin-1, 220); 
  
  delay(700); 
     analogWrite(pin, 150);  
       analogWrite(pin+1, 150);   
  analogWrite(pin-1, 150); 
  
  delay(800); 
      analogWrite(pin, 250);   
        analogWrite(pin+1, 250);   
  analogWrite(pin-1, 250); 
 
  delay(200); 
      analogWrite(pin, 200);  
        analogWrite(pin+1, 200);   
  analogWrite(pin-1, 200); 
  
  delay(400); 
}
      break;
    case 6:
      //выполняется, когда var равно 6
{
        analogWrite(pin, 200);    
          analogWrite(pin+1, 200);   
  analogWrite(pin-1, 200); 

  delay(700);  
   analogWrite(pin, 240);   
     analogWrite(pin+1, 240);   
  analogWrite(pin-1, 240); 
 
  delay(1300); 
    analogWrite(pin, 190);   
      analogWrite(pin+1, 190);   
  analogWrite(pin-1, 190); 
 
  delay(600); 
     analogWrite(pin, 250);  
       analogWrite(pin+1, 250);   
  analogWrite(pin-1, 250); 
  
  delay(700); 
      analogWrite(pin, 180);  
        analogWrite(pin+1, 180);   
  analogWrite(pin-1, 180); 
  
  delay(800); 
      analogWrite(pin, 230); 
        analogWrite(pin+1, 230);   
  analogWrite(pin-1, 230); 
   
  delay(300); 
}   
      break;
    case 7:
      //выполняется когда  var равно 7
{
  for (int i = 0 ; i <= 5; i += 1)
  {
  rand2 = random(50);
 // Serial.println(randNumber); 
  analogWrite(pin, 255-rand2);
    analogWrite(pin+1, 255-rand2);
  delay(900-rand2*5);
  analogWrite(pin, 200+rand2);
   analogWrite(pin+1, 100+rand2);
   delay(900-rand2*5);
  }

}
      break;

   // default:
      // выполняется, если не выбрана ни одна альтернатива
      // default необязателен
  
  }
  }
//  }
   /* {
  
  digitalWrite(3, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(3, LOW);    // turn the LED off by making the voltage LOW
  delay(100);              // wait for a second

  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(3, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(3);
  }


 analogWrite(2, 255);
 digitalWrite(4, HIGH);  
 delay(100); 
 analogWrite(2, 0);
 digitalWrite(4, LOW); 
 delay(100); 
 

    digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
  }}
  */
