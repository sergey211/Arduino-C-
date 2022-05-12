
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN        5 // 9           // Configurable, see typical pin layout above
#define SS_PIN       53 //   10          // Configurable, see typical pin layout above

MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

byte buffer[18];
byte block;
byte waarde[64][16];
MFRC522::StatusCode status;
    
MFRC522::MIFARE_Key key;

#define NR_KNOWN_KEYS   8
// Known keys, see: https://code.google.com/p/mfcuk/wiki/MifareClassicDefaultKeys
byte knownKeys[NR_KNOWN_KEYS][MFRC522::MF_KEY_SIZE] =  {
    {0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, // FF FF FF FF FF FF = factory default
    {0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5}, // A0 A1 A2 A3 A4 A5
    {0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xb5}, // B0 B1 B2 B3 B4 B5
    {0x4d, 0x3a, 0x99, 0xc3, 0x51, 0xdd}, // 4D 3A 99 C3 51 DD
    {0x1a, 0x98, 0x2c, 0x7e, 0x45, 0x9a}, // 1A 98 2C 7E 45 9A
    {0xd3, 0xf7, 0xd3, 0xf7, 0xd3, 0xf7}, // D3 F7 D3 F7 D3 F7
    {0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff}, // AA BB CC DD EE FF
    {0x00, 0x00, 0x00, 0x00, 0x00, 0x00}  // 00 00 00 00 00 00
};

char choice;

void setup() {
    Serial.begin(9600);         // Initialize serial communications with the PC
    while (!Serial);            // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
    SPI.begin();                // Init SPI bus
    mfrc522.PCD_Init();         // Init MFRC522 card
    Serial.println(F("1.SCHITAT KARTU \n3.KOPIROVAT DANNYE"));

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }
}



 //Via seriele monitor de bytes uitlezen in hexadecimaal
 
void dump_byte_array(byte *buffer, byte bufferSize) {
    for (byte i = 0; i < bufferSize; i++) {
        Serial.print(buffer[i] < 0x10 ? " 0" : " ");
        Serial.print(buffer[i], HEX);
    }
}
//Via seriele monitor de bytes uitlezen in ASCI

void dump_byte_array1(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.write(buffer[i]);
  }
}

bool try_key(MFRC522::MIFARE_Key *key)
{
    bool result = false;
    
    for(byte block = 0; block < 64; block++){
      
    // Serial.println(F("Authenticating using key A..."));
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PCD_Authenticate() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return false;
    }

    // Read block
    byte byteCount = sizeof(buffer);
    status = mfrc522.MIFARE_Read(block, buffer, &byteCount);
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("MIFARE_Read() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
    }
    else {
        // Successful read
        result = true;
        Serial.print(F("USPESHNO:"));
        dump_byte_array((*key).keyByte, MFRC522::MF_KEY_SIZE);
        Serial.println();
        
        // Dump block data
        Serial.print(F("BLOK ")); Serial.print(block); Serial.print(F(":"));
        dump_byte_array1(buffer, 16); //omzetten van hex naar ASCI
        Serial.println();
        
        for (int p = 0; p < 16; p++) //De 16 bits uit de block uitlezen
        {
          waarde [block][p] = buffer[p];
          Serial.print(waarde[block][p]);
          Serial.print(" ");
        }
        
        }
    }
    Serial.println();
    
    Serial.println(F("1.SCHITAT KARTU \n3.KOPIROVAT DANNYE"));

    mfrc522.PICC_HaltA();       // Halt PICC
    mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
    return result;
    
    start();
}

void loop() {
  start();    
}

void start(){
  choice = Serial.read();
  
  if(choice == '1')
  {
    Serial.println(F("SCHITAT"));
    keuze1();
      
    }
   else if(choice == '3')
    {
      Serial.println(F("KOPIROVAT NA NOVYE"));
      keuze3();
    }
}

void keuze2(){ 
  
  for(block = 1; block <= 62; block++){
    if(block == 3 || block == 7 || block == 11 || block == 15 || block == 19 || block == 23 || block == 27 || block == 31 || block == 35 || block == 39 || block == 43 || block == 47 || block == 51 || block == 55 || block == 59){
      block ++;
    }
  
  Serial.print(F("ZAPIS V BLOK ")); 
  Serial.print(block);
  Serial.println(F("\n"));
  
    for(int j = 0; j < 16; j++){
      Serial.print(waarde[block][j]);
      Serial.print(" ");
    }
    Serial.println(F("\n"));
    
  }
  
  Serial.println(F("1.SCHITAT KARTU \n3.KOPIROVAT DANNYE"));
  start();
}

void keuze3(){ // Копирование данных на новую карту
Serial.println(F("PODNECITE NOVUYU KARTU"));
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)
    Serial.print(F(" NOMER UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
    Serial.print(F("TIP KARTY: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));

    for (byte i = 0; i < 6; i++) {
        key.keyByte[i] = 0xFF;
    }

  for(int i = 1; i <= 62; i++){ //De blocken 1 tot 62 kopieren, behalve al deze onderstaande blocken (omdat deze de authenticatie blokken zijn)
    if(i == 3 || i == 7 || i == 11 || i == 15 || i == 19 || i == 23 || i == 27 || i == 31 || i == 35 || i == 39 || i == 43 || i == 47 || i == 51 || i == 55 || i == 59){
      i++;
    }
    block = i;
    
    Serial.println(F("PROVERKA KLUCHA A..."));
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, block, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PROVERKA KLUCHA A - OSHIBKA: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    
    Serial.println(F("PROVERKA KLUCHA B..."));
    status = (MFRC522::StatusCode) mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_B, block, &key, &(mfrc522.uid));
    if (status != MFRC522::STATUS_OK) {
        Serial.print(F("PROVERKA KLUCHA B - OSHIBKA: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    
    Serial.print(F("ZAPIS BLOKA ")); 
    Serial.print(block);
    Serial.println(F("\n"));
          
    dump_byte_array(waarde[block], 16); 
    
          
     status = (MFRC522::StatusCode) mfrc522.MIFARE_Write(block, waarde[block], 16);
      if (status != MFRC522::STATUS_OK) {
        Serial.print(F("OSHIBKA ZAPISI: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
      }        
     Serial.println(F("\n"));     
  }
  mfrc522.PICC_HaltA();       // Halt PICC
  mfrc522.PCD_StopCrypto1();  // Stop encryption on PCD
  
  Serial.println(F("1.SCHITAT KARTU \n3.KOPIROVAT DANNYE"));
  start();
}

void keuze1(){
  Serial.println(F("PODNESI KARTU ... "));
    if ( ! mfrc522.PICC_IsNewCardPresent())
        return;

    if ( ! mfrc522.PICC_ReadCardSerial())
        return;

    // Show some details of the PICC (that is: the tag/card)
    Serial.print(F("NOMER UID:"));
    dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size);
    Serial.println();
    Serial.print(F("TYP KARTY: "));
    MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
    Serial.println(mfrc522.PICC_GetTypeName(piccType));
 
    MFRC522::MIFARE_Key key;
    for (byte k = 0; k < NR_KNOWN_KEYS; k++) {
        for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {
            key.keyByte[i] = knownKeys[k][i];
        }
        // Try the key
        if (try_key(&key)) {
            // Found and reported on the key and block,
            // no need to try other keys for this PICC
            break;
        }
    }
}
