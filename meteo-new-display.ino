#include <iarduino_RTC.h>                                   // Подключаем библиотеку iarduino_RTC для работы с модулями реального времени.
iarduino_RTC time(RTC_DS1302, 10, 3, 9);
#include "DHT.h"
#include <TM74HC595DisplayF.h>
#include <TimerOne.h>
#include <SPI.h>
#include <SD.h>

File myFile;

#define DHTPIN 2 
#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

int SCLK = 7;
int RCLK = 6;
int DIO = 5;
TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char LED_0F[29];
void timerIsr();

void setup(){    

dht.begin();                                           //

  LED_0F[0] = 0xC0; //0
  LED_0F[1] = 0xF9; //1
  LED_0F[2] = 0xA4; //2
  LED_0F[3] = 0xB0; //3
  LED_0F[4] = 0x99; //4
  LED_0F[5] = 0x92; //5
  LED_0F[6] = 0x82; //6
  LED_0F[7] = 0xF8; //7
  LED_0F[8] = 0x80; //8
  LED_0F[9] = 0x90; //9
  LED_0F[10] = 0x88; //A
  LED_0F[11] = 0x83; //b
  LED_0F[12] = 0xC6; //C
  LED_0F[13] = 0xA1; //d
  LED_0F[14] = 0x86; //E
  LED_0F[15] = 0x8E; //F
  LED_0F[16] = 0xC2; //G
  LED_0F[17] = 0x89; //H
  LED_0F[18] = 0xF9; //I
  LED_0F[19] = 0xF1; //J
  LED_0F[20] = 0xC3; //L
  LED_0F[21] = 0xA9; //n
  LED_0F[22] = 0xC0; //O
  LED_0F[23] = 0x8C; //P
  LED_0F[24] = 0x98; //q
  LED_0F[25] = 0x92; //S
  LED_0F[26] = 0xC1; //U
  LED_0F[27] = 0x91; //Y
  LED_0F[28] = 0xFE; //hight -
  
    delay(300);                                             // Ждем готовности модуля отвечать на запросы
    Serial.begin(9600);                                     // Инициируем передачу данных в монитор последовательного порта на скорости 9600 бод.
    time.begin();                                           // Инициируем работу с модулем.

  Timer1.initialize(1500); // set a timer of length 1500
  Timer1.attachInterrupt(timerIsr); // attach the service routine here


  disp.set(LED_0F[17], 3);    //send digital "H" to 1st indicator
  delay(1000);
  
  disp.set(LED_0F[18], 2);    //send digital "I" to 2nd indicator
  delay(1000);
   
  disp.set(LED_0F[28], 1);    //send simbol "-" to 3rd indicators
  delay(500);

  disp.set(LED_0F[28], 0);    //send simbol "-" to 4rd indicators
  delay(500);

  disp.clear(); 

    Serial.print("Initializing SD card...");

  if (!SD.begin(4)) {
    Serial.println("initialization SD failed!");
    return;
  }
  Serial.println("initialization done.");

  
  
}                                                           //
void loop(){                                                //

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!

   myFile = SD.open("LOG.txt", FILE_WRITE);
     // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to LoG.txt...");
 //   myFile.println("NASHI DANNYE");


       myFile.print(time.gettime("d-m-Y, H:i:s, D, "));
  if (isnan(t) || isnan(h)) {

 
    myFile.println("Failed to read from DHT");
  } else {
   
    myFile.print("Temperature: "); 
    myFile.print(t);
    myFile.print(" *C, ");
    
    myFile.print("Humidity: "); 
    myFile.print(h);
    myFile.println(" %\t");
    
    // close the file:
    myFile.close();
    Serial.println("writing to SD done.");
  
  disp.set(LED_0F[25], 3);    //send digital "S" to 1st indicator
  disp.set(LED_0F[13], 2);    //send digital "d" to 2nd indicator
  disp.set(LED_0F[28], 1);    //send digital "-" to 2nd indicator
  disp.set(LED_0F[16], 0);    //send digital "G" to 2nd indicator
  delay(1000);
  
  }} else {
    // if the file didn't open, print an error:
    Serial.println("error opening LoGiRoVaNiE.txt");
   disp.set(LED_0F[25], 3);    //send digital "S" to 1st indicator
  disp.set(LED_0F[13], 2);    //send digital "d" to 2nd indicator
  disp.set(LED_0F[28], 1);    //send digital "-" to 2nd indicator
  disp.set(LED_0F[14], 0);    //send digital "E" to 2nd indicator
  delay(5000);
  }
       
       Serial.print(time.gettime("d-m-Y, H:i:s, D, "));
  if (isnan(t) || isnan(h)) {

 
    Serial.println("Failed to read from DHT");
  } else {
   
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" *C, ");
    
    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.println(" %\t");
 
  //  Serial.println("Temperature: ", t); //+ " *C, Humidity: " +h+ " %");   
  }
  
  
  for(int j = 1; j<=7; j++){
   
   String ti = (String)time.gettime("H")+(String)time.gettime("i"); // получаем время формата "1025" 
  
 
  int tiint = atoi(ti.c_str());
  disp.digit4showZero(tiint);
  delay(500);
 // disp.clear(); 

  String tifl = (String)time.gettime("H")+"."+(String)time.gettime("i"); // получаем время формата "10.25" 
  float tifloat = tifl.toFloat();

   disp.dispFloat(tifloat, 2);
   delay(500);
 // disp.clear(); 
  
  }
  
//   Serial.println("time = "+ti);

 

//}

   
   String  dati = (String)time.gettime("d")+"."+(String)time.gettime("m"); // выводим дату 1 секунду
   Serial.println("date = "+dati);
    
//  int datiint = atoi(dati.c_str());
  float datfloat = dati.toFloat();
//  Serial.println("datiint ="+datiint);
  disp.dispFloat(datfloat,2); 
 delay(1000);
 disp.clear();
  
  
//int tempint = static_cast<int>(t);
int humint = static_cast<int>(h);  

  disp.set(LED_0F[15], 3); 
  disp.dispFloat(t, 0); //send float indicators
  delay(1000);
  disp.clear();   //clear display

    disp.set(LED_0F[17], 3);    //send digital "H" to 1st indicator
 //  disp.digit4showZero(t, 1000); 
   disp.digit4(h);
   delay(1000);
// disp.clear(); 
  
                                                      
}  

void timerIsr()
{
  disp.timerIsr();
}

