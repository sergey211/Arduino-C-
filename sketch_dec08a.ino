#include <Wire.h>
#include "DHT.h"
#include <TM74HC595Display.h>
#include  <SPI.h>
#include  <SD.h>
#include <OneWire.h>
#include "RTClib.h"
//#include <BMP085.h>
//BMP085  _bmp085 = BMP085();
long _bmp085P = 0;
long _bmp085T = 0;
long _bmp085A = 0;
RTC_DS1307  _RTC1;
DateTime  _tRTC1;
File _sd1DF;
String _sd1TS;
//LiquidCrystal_I2C _lcd1(0x3F, 20, 4);
int _dispTempLength1 = 0;
boolean _isNeedClearDisp1;
DHT _dht1(2, DHT22);
byte _d18x2x1Addr[8] = {0x28, 0xFF, 0x11, 0x94, 0x3C, 0x4, 0x0, 0x48};
OneWire  _ow3(3);
String _gtv1;
String _gtv2;
String _gtv3;
String _gtv4;
String _gtv5;
String _gtv6;
bool _gtv7 = 0;
int _gtv8 = 0;
bool _gtv9 = 0;
bool _gtv10 = 0;
bool _gen1I = 0;
bool _gen1O = 0;
unsigned long _gen1P = 0UL;
unsigned long _d18x2x1Tti = 0UL;
float _d18x2x1O = 0.00;
bool _sd1SVOS1 = 0;
unsigned long _bmp0851Tti = 0UL;
bool _sd1SVOS2 = 0;
bool _sd1SVOS3 = 0;
bool _sd1SVOS4 = 0;
unsigned long _dht1Tti = 0UL;
float _dht1t = 0.00;
float _dht1h = 0.00;
bool _sd1SVOS5 = 0;
bool _sd1SVOS6 = 0;
bool _count1I = 0;
int _count1P = 0;
bool _trgs1 = 0;
bool _D1B1 = 0;
bool _tim1I = 0;
bool _tim1O = 0;
unsigned long _tim1P = 0UL;
int _disp1oldLength = 0;
int _disp2oldLength = 0;
String _mux1;
int _disp3oldLength = 0;
String _mux2;
int _disp4oldLength = 0;
String _mux3;
int _disp5oldLength = 0;
bool _sd1UFOS1 = 0;
bool _bounseInput9S = 0;
bool _bounseInput9O = 0;
unsigned long _bounseInput9P = 0UL;
bool _bounseInput6S = 0;
bool _bounseInput6O = 0;
unsigned long _bounseInput6P = 0UL;
bool _bounseInput4S = 0;
bool _bounseInput4O = 0;
unsigned long _bounseInput4P = 0UL;
bool _bounseInput5S = 0;
bool _bounseInput5O = 0;
unsigned long _bounseInput5P = 0UL;

int SCLK = 7;
int RCLK = 6;
int DIO = 5;

TM74HC595Display disp(SCLK, RCLK, DIO);
unsigned char LED_0F[29];


void setup()
{
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

  Wire.begin();
//  _bmp085.init(MODE_ULTRA_HIGHRES, 300, true);
  _RTC1.begin();
  Serial.begin(9600);
  pinMode(5, INPUT);
  digitalWrite(5, HIGH);
  pinMode(4, INPUT);
  digitalWrite(4, HIGH);
  pinMode(9, INPUT);
  digitalWrite(9, HIGH);
  pinMode(6, INPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
/*
  _lcd1.init();
  _lcd1.noBacklight();
  _bounseInput9O =  digitalRead(9);
  _bounseInput6O =  digitalRead(6);
  _bounseInput4O =  digitalRead(4);
  _bounseInput5O =  digitalRead(5);
  */
  _dht1.begin();
  SD.begin(8);
  SPI.begin();
  pinMode(10, OUTPUT);
}
void loop()
{
  disp.send(LED_0F[0], 0b0001);    //send digital "0" to 1st indicator
  delay(1000);
  disp.send(LED_0F[3], 0b0110);    //send digital "3" to 2nd and 3rd indicator
  delay(1000);
  disp.send(LED_0F[10], 0b1111);    //send simbol "A" to all indicators
  delay(1000);
  
  
 _tRTC1 = _RTC1.now();
  if (_isTimer(_dht1Tti, 8000)) {
    _dht1Tti = millis();
    float tempDht2;
    tempDht2 = _dht1.readTemperature();
    if (!(isnan(tempDht2))) {
      _dht1t = tempDht2;
    }
    tempDht2 = _dht1.readHumidity();
    if (!(isnan(tempDht2))) {
      _dht1h = tempDht2;
    }
  } if (_isNeedClearDisp1) {
 //   _lcd1.clear();
    _isNeedClearDisp1 = 0;
  }
 /* if (_isTimer(_bmp0851Tti, 6000)) {
    _bmp0851Tti = millis();
    _bmp085.getAltitude(&_bmp085A);
    _bmp085.getPressure(&_bmp085P);
    _bmp085.getTemperature(&_bmp085T);
  }
  */
  bool  _bounceTmp9 =  (digitalRead (9));

  if (_bounseInput9S)
  {
    if (millis() >= (_bounseInput9P + 40))
    {
      _bounseInput9O = _bounceTmp9;
      _bounseInput9S = 0;
    }
  }
  else
  {
    if (_bounceTmp9 != _bounseInput9O )
    {
      _bounseInput9S = 1;
      _bounseInput9P = millis();
    }
  }
  bool  _bounceTmp6 =  (digitalRead (6));

  if (_bounseInput6S)
  {
    if (millis() >= (_bounseInput6P + 40))
    {
      _bounseInput6O = _bounceTmp6;
      _bounseInput6S = 0;
    }
  }
  else
  {
    if (_bounceTmp6 != _bounseInput6O )
    {
      _bounseInput6S = 1;
      _bounseInput6P = millis();
    }
  }
  bool  _bounceTmp4 =  (digitalRead (4));

  if (_bounseInput4S)
  {
    if (millis() >= (_bounseInput4P + 40))
    {
      _bounseInput4O = _bounceTmp4;
      _bounseInput4S = 0;
    }
  }
  else
  {
    if (_bounceTmp4 != _bounseInput4O )
    {
      _bounseInput4S = 1;
      _bounseInput4P = millis();
    }
  }
  bool  _bounceTmp5 =  (digitalRead (5));

  if (_bounseInput5S)
  {
    if (millis() >= (_bounseInput5P + 40))
    {
      _bounseInput5O = _bounceTmp5;
      _bounseInput5S = 0;
    }
  }
  else
  {
    if (_bounceTmp5 != _bounseInput5O )
    {
      _bounseInput5S = 1;
      _bounseInput5P = millis();
    }
  }




  if (1)
  {
    if (! _gen1I)
    {
      _gen1I = 1;
      _gen1O = 1;
      _gen1P = millis();
    }
  }
  else
  {
    _gen1I = 0 ;
    _gen1O = 0;
  }
  if (_gen1I )
  {
    if ( _isTimer ( _gen1P , 5000 ))
    {
      _gen1P = millis();
      _gen1O = ! _gen1O;
    }
  }
  digitalWrite(7, !(_bounseInput9O));
  _gtv10 =  (_gen1O) && (!(_bounseInput9O)) ;
  if (_isTimer(_d18x2x1Tti, 5000)) {
    _d18x2x1Tti = millis();
    _d18x2x1O =  _readDS18_ow3(_d18x2x1Addr, 0);
  }
  if (_gtv10)
  { if (! _sd1SVOS1) {
      _sd1TS = "ds18b20;";
      _sd1TS += "Float;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += ( _floatToStringWitRaz((_d18x2x1O), 2));
      _sd1TS += ";";
      _sd1TS += "C";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS1 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS1) {
      _sd1SVOS1 = 0;
    }
  }
  _gtv1 = ((String("T-")) + (( _floatToStringWitRaz((_d18x2x1O), 2))) + (String("C")));
  if (_gtv10)
  { if (! _sd1SVOS4) {
      _sd1TS = "bmp085a;";
      _sd1TS += "Integer;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += (String(_bmp085A));
      _sd1TS += ";";
      _sd1TS += "cm";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS4 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS4) {
      _sd1SVOS4 = 0;
    }
  }
  if (_gtv10)
  { if (! _sd1SVOS3) {
      _sd1TS = "bmp085p;";
      _sd1TS += "Integer;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += (String((_bmp085P) / (1000)));
      _sd1TS += ";";
      _sd1TS += "kPa";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS3 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS3) {
      _sd1SVOS3 = 0;
    }
  }
  if (_gtv10)
  { if (! _sd1SVOS2) {
      _sd1TS = "bmp085t;";
      _sd1TS += "Float;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += ( _floatToStringWitRaz((_bmp085T) / (10.00), 2));
      _sd1TS += ";";
      _sd1TS += "C";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS2 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS2) {
      _sd1SVOS2 = 0;
    }
  }
  _gtv2 = ((String("T-")) + (( _floatToStringWitRaz((_bmp085T) / (10.00), 1))) + (String("C")));
  _gtv3 = ((String("P-")) + ((String((_bmp085P) / (1000)))) + (String("kPa")));
  _gtv4 = ((String("A")) + ((String(_bmp085A))) + (String("cm")));
  if (_gtv10)
  { if (! _sd1SVOS6) {
      _sd1TS = "dht22h;";
      _sd1TS += "Float;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += ( _floatToStringWitRaz(_dht1h, 2));
      _sd1TS += ";";
      _sd1TS += "%";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS6 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS6) {
      _sd1SVOS6 = 0;
    }
  }
  if (_gtv10)
  { if (! _sd1SVOS5) {
      _sd1TS = "dht22t;";
      _sd1TS += "Float;";
      _sd1TS += String(_tRTC1.day());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.month());
      _sd1TS += ":";
      _sd1TS += String(_tRTC1.year());
      _sd1TS += " ";
      _sd1TS += String(_tRTC1.hour());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.minute());
      _sd1TS += "-";
      _sd1TS += String(_tRTC1.second());
      _sd1TS += ";";
      _sd1TS += ( _floatToStringWitRaz(_dht1t, 2));
      _sd1TS += ";";
      _sd1TS += "C";
      _sd1TS += ";";
      _sd1DF = SD.open("test.csv", FILE_WRITE);
      if (_sd1DF) {
        _sd1DF.println(_sd1TS);
        _sd1DF.close();
      }
      _sd1SVOS5 = 1;
    }
  }
  else
  {
    if ( _sd1SVOS5) {
      _sd1SVOS5 = 0;
    }
  }
  _gtv5 = ((String("T-")) + (( _floatToStringWitRaz(_dht1t, 2))) + (String("C")));
  _gtv6 = ((String("H-")) + (( _floatToStringWitRaz(_dht1h, 2))) + (String("%")));

  if (!(_bounseInput5O))
  {
    if (! _count1I)
    {
      _count1P = _count1P + 1;
      _count1I = 1;
    }
  }
  else
  {
    _count1I = 0;
  }
  if (_count1P < 0 ) _count1P = 0;
  if (_gtv7) _count1P = 0;
  _gtv7 =  _count1P  >=  3;
  _gtv8 = _count1P;
  if ( (!(_bounseInput4O)) || (!(_bounseInput5O)) ) _trgs1 = 1;
  if (_gtv9) _trgs1 = 0;
  if ( (_trgs1) && (_bounseInput5O) )
  {
    if (_tim1I)
    {
      if ( _isTimer(_tim1P, 20000)) _tim1O = 1;
    }
    else
    {
      _tim1I = 1;
      _tim1P = millis();
    }
  }
  else
  {
    _tim1O = 0;
    _tim1I = 0;
  }
  if (_trgs1) {
    if (! _D1B1) {
//      _lcd1.backlight();
      _D1B1 = 1;
    }
  } else {
    if (_D1B1) {
 //     _lcd1.noBacklight();
      _D1B1 = 0;
    }
  }
  _gtv9 = _tim1O;
  if (1) {
    _dispTempLength1 = (((((String((_tRTC1.hour())))) + (String(":")) + ((String((_tRTC1.minute())))) + (String(":")) + ((String((_tRTC1.second()))))))).length();
    if (_disp1oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp1oldLength = _dispTempLength1;
 //   _lcd1.setCursor(0, 0);
//    _lcd1.print(((((String((_tRTC1.hour())))) + (String(":")) + ((String((_tRTC1.minute())))) + (String(":")) + ((String((_tRTC1.second())))))));
  } else {
    if (_disp1oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp1oldLength = 0;
    }
  }
  if (1) {
    _dispTempLength1 = (((((String((_tRTC1.day())))) + (String("-")) + ((String((_tRTC1.month())))) + (String("-")) + ((String((_tRTC1.year()))))))).length();
    if (_disp2oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp2oldLength = _dispTempLength1;
 //   _lcd1.setCursor(9, 0);
 //   _lcd1.print(((((String((_tRTC1.day())))) + (String("-")) + ((String((_tRTC1.month())))) + (String("-")) + ((String((_tRTC1.year())))))));
  } else {
    if (_disp2oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp2oldLength = 0;
    }
  }
  if ((_gtv8) == 0) {
    _mux1 = String("DS18B2");
  }
  if ((_gtv8) == 1) {
    _mux1 = String("Bmp-085");
  }
  if ((_gtv8) == 2) {
    _mux1 = String("DHT-22");
  }
  if (1) {
    _dispTempLength1 = ((_mux1)).length();
    if (_disp3oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp3oldLength = _dispTempLength1;
 //   _lcd1.setCursor(int((20 - _dispTempLength1) / 2), 1);
  //  _lcd1.print((_mux1));
  } else {
    if (_disp3oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp3oldLength = 0;
    }
  }
  if ((_gtv8) == 0) {
    _mux2 = _gtv1;
  }
  if ((_gtv8) == 1) {
    _mux2 = _gtv2;
  }
  if ((_gtv8) == 2) {
    _mux2 = _gtv5;
  }
  if (1) {
    _dispTempLength1 = ((_mux2)).length();
    if (_disp4oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp4oldLength = _dispTempLength1;
 //   _lcd1.setCursor(0, 2);
  //  _lcd1.print((_mux2));
  } else {
    if (_disp4oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp4oldLength = 0;
    }
  }
  if ((_gtv8) == 0) {
    _mux3 = String("-----");
  }
  if ((_gtv8) == 1) {
    _mux3 = ((_gtv3) + (String("/")) + (_gtv4));
  }
  if ((_gtv8) == 2) {
    _mux3 = _gtv6;
  }
  if (1) {
    _dispTempLength1 = ((_mux3)).length();
    if (_disp5oldLength > _dispTempLength1) {
      _isNeedClearDisp1 = 1;
    }
    _disp5oldLength = _dispTempLength1;
  //  _lcd1.setCursor(0, 3);
 //   _lcd1.print((_mux3));
  } else {
    if (_disp5oldLength > 0) {
      _isNeedClearDisp1 = 1;
      _disp5oldLength = 0;
    }
  }
  if (!(_bounseInput6O)) {
    if (! _sd1UFOS1) {
      _sd1DF = SD.open("test.csv");
      if (_sd1DF) {
        while (_sd1DF.available()) {
          Serial.write(_sd1DF.read());
        } _sd1DF.close();
      } _sd1UFOS1 = 1;
    }
  } else {
    if ( _sd1UFOS1) {
      _sd1UFOS1 = 0;
    }
  }


}
bool _isTimer(unsigned long startTime, unsigned long period )
{
  unsigned long endTime;
  endTime = startTime + period;
  return (millis() >= endTime);
}
String  _floatToStringWitRaz(float value, int raz)
{
  float tv;
  int ti = int(value);
  String ts = String(ti);
  if (raz == 0) {
    return ts;
  }
  ts += ".";
  float tf = abs(value - ti);
  for (int i = 1; i <= raz; i++ )
  {
    tv = tf * 10;
    ti = int(tv);
    ts += String(ti);
    tf = (tv - ti);
  }
  return ts;
}
float _convertDS18x2xData(byte type_s, byte data[12])
{
  int16_t raw = (data[1] << 8) | data[0];
  if (type_s)
  {
    raw = raw << 3;
    if (data[7] == 0x10) {
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  }
  else
  {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;   else if (cfg == 0x20) raw = raw & ~3;  else if (cfg == 0x40) raw = raw & ~1;
  }
  return  (float)raw / 16.0;
}
float _readDS18_ow3(byte addr[8], byte type_s)
{ byte data[12];
  byte i;
  _ow3.reset();
  _ow3.select(addr);
  _ow3.write(0xBE);
  for ( i = 0; i < 9; i++) {
    data[i] = _ow3.read();
  }
  _ow3.reset();
  _ow3.select(addr);
  _ow3.write(0x44, 1);
  return _convertDS18x2xData(type_s, data);
}
