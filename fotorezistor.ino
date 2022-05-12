int init1 = 0;
int valueaverage = 0;
int value110 = 0;
int value = 0;
int maxvalue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
    

}

void loop() {



if (init1==0) { 
      int value1 = analogRead(A0);

  Serial.println("Analog value 1 : ");
  Serial.println(value1);
    delay(250);

     int value2 = analogRead(A0);
     Serial.println("Analog value 2 : ");
  Serial.println(value2);
         delay(250);
     int value3 = analogRead(A0);
     Serial.println("Analog value 3 : ");
  Serial.println(value3);
         delay(250);
     int value4 = analogRead(A0);
     Serial.println("Analog value 4 : ");
  Serial.println(value4);
         delay(250);
     int value5 = analogRead(A0);
     Serial.println("Analog value 5 : ");
  Serial.println(value5);
  int sum = value1+value2+value3+value4+value5;
      valueaverage =  (sum/5);
      delay(250);
       Serial.print("Average value : ");
  Serial.println(valueaverage);
  init1=init1+1;
}
  else {
  value = analogRead(A0);
  Serial.print("Analog value : ");
  Serial.println(value);
  Serial.print("Average value : ");
  Serial.println(valueaverage);
  value110 = valueaverage*11;
//       Serial.print("Value11 : ");
//  Serial.println(value110);
   maxvalue = value110/10;
    Serial.print("Maxvalue = ");
    Serial.println(maxvalue);
  if (value>maxvalue) {digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("srabotalo, pauza");
      delay(2250);}
  else {digitalWrite(LED_BUILTIN, LOW);}
  delay(1250);
  }
}
