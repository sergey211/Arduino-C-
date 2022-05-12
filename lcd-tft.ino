#include <Adafruit_GFX.h> // Libreria de graficos
#include <Adafruit_TFTLCD.h> // Libreria de LCD
#include <OneWire.h>
//#include <DallasTemperature.h>
#define LCD_CS A3  // Chip Select - Pin analogico 3
#define LCD_CD A2 // Command/Data - Pin Analogico 2
#define LCD_WR A1 // LCD Write - Pin Analogico 1
#define LCD_RD A0 // LCD Read - Pin Analogico 0
#define LCD_RESET A4 // LCD Reset - Pin Analogico 4
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
// Instancia del LCD
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
#define ONE_WIRE_BUS 11
OneWire oneWire(ONE_WIRE_BUS);
//DallasTemperature sensors(&oneWire);
 
void setup()
{
pinMode(13, OUTPUT);
 tft.begin(0x9341);
 tft.fillScreen(BLACK);
 tft.setRotation(1);
//sensors.begin();
}
void loop(){
  
//sensors.requestTemperatures();

tft.setCursor(0, 30);
tft.setTextColor(YELLOW,BLACK);
tft.setTextSize(3);
tft.print(utf8rus("ОТОПЛЕНИЕ C -> "));
//tft.print(sensors.getTempCByIndex(1),0);

tft.setCursor(0, 60);
tft.setTextColor(YELLOW,BLACK);
tft.setTextSize(3);
tft.print(utf8rus("КОТЕЛ C -> "));
//tft.print(sensors.getTempCByIndex(3),0);

//if (sensors.getTempCByIndex(3) > 25)
  {
    digitalWrite(13, HIGH);
    tft.setTextSize(3);
    tft.drawRoundRect(12, 160, 290, 60, 30, GREEN);
    tft.setTextColor(GREEN,BLACK);
    tft.setCursor(22, 180);  
    tft.print(utf8rus(" ДВИГАТЕЛЬ ВКЛ "));
  }
 //else if (sensors.getTempCByIndex(3) < 25)
 { 
  digitalWrite(13, LOW);  
    tft.setTextSize(3);
      tft.drawRoundRect(12, 160, 290, 60, 30, RED);
    tft.setTextColor(RED,BLACK);
    tft.setCursor(32, 180);
    tft.print(utf8rus("ДВИГАТЕЛЬ ВЫКЛ"));
}

tft.setCursor(0, 90);  
tft.setTextSize(3);
tft.setTextColor(YELLOW,BLACK);
tft.print(utf8rus("ДОМ C -> "));
//tft.print(sensors.getTempCByIndex(0),0);

tft.drawLine(0, 25, 320, 25, GREEN);
tft.drawLine(0, 115, 320, 115, GREEN);
tft.drawLine(0, 115, 320, 115, GREEN); 
tft.drawLine(0, 140, 320, 140, GREEN);


   tft.setCursor(15, 5);  
    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.print(utf8rus("ТЕМПЕРАТУРА КОТЛА И ДОМА")); 

    tft.setCursor(45, 120);  
tft.setTextSize(2);
tft.setTextColor(WHITE);
tft.print(utf8rus("ПОЛОЖЕНИЕ ДВИГАТЕЛЯ"));
}
