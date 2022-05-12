#include <iarduino_RTC.h>                                   // Подключаем библиотеку iarduino_RTC для работы с модулями реального времени.
iarduino_RTC time(RTC_DS1302, 10, 3, 9);

#include "DHT.h"
#define DHTPIN 2 

#define DHTTYPE DHT11   // DHT 11 
//#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE);

#include <TM74HC595Display.h>

int SCLK = 7;
int RCLK = 6;
int DIO = 5;

TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char LED_0F[29];

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

  disp.send(LED_0F[17], 0b1000);    //send digital "H" to 1st indicator
  delay(1000);
  disp.send(LED_0F[18], 0b0100);    //send digital "I" to 2nd and 3rd indicator
  delay(1000);
  disp.send(LED_0F[28], 0b1111);    //send simbol "-" to all indicators
  delay(500);
  
}                                                           //
void loop(){                                                //

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
  
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" *C ");
    
    Serial.print(" Humidity: "); 
    Serial.print(h);
    Serial.println(" %\t");

  }
  

   String ti = (String)time.gettime("H")+(String)time.gettime("i"); // выводим время 1 секунду
   Serial.print("time = "+ti);
    
  int tiint = atoi(ti.c_str());
//  Serial.println("tiint ="+tiint); // вызывает билиберду в мониторе порта и 0 на дисплее
  disp.digit4showZero(tiint, 2000); 
//}

   
   String  dati = (String)time.gettime("d")+(String)time.gettime("m"); // выводим дату 1 секунду
   Serial.println(", date = "+dati);
   
   Serial.println(time.gettime("d-m-Y, H:i:s, D"));
    
  int datiint = atoi(dati.c_str());
//  Serial.println("datiint ="+datiint);
  disp.digit4showZero(datiint, 1000); 
  
  
int tempint = static_cast<int>(t);

int humint = static_cast<int>(h);  
//disp.dispFloat(t, 2); //send float indicators
  


//int m = -25;
// disp.digit4(m, 1000); 
  disp.digit4showZero(t, 1000); 
   disp.digit4showZero(h, 1000); 
  
                                                      
}  
