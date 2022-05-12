//простое подключение A4988
//пины reset и sleep соединены вместе
//подключите VDD к пину 3.3 В или 5 В на Arduino
//подключите GND к Arduino GND (GND рядом с VDD)
//подключите 1A и 1B к 1 катушке шагового двигателя
//подключите 2A и 2B к 2 катушке шагового двигателя
//подключите VMOT к источнику питания (9В источник питания + term)
//подключите GRD к источнику питания (9В источник питания - term)

int stp = 13; //подключите 13 пин к step
int dir = 12; //подключите 12 пин к dir
int a = 0;

void setup()

{
  Serial.begin(115200);
pinMode(stp, OUTPUT);
pinMode(dir, OUTPUT);
}

void loop()

{
if (a < 100) // вращение на 200 шагов в направлении 1
  {
  a++;
  digitalWrite(stp, HIGH);
  delay(50);
  digitalWrite(stp, HIGH);
  delay(25);
    digitalWrite(stp, LOW);
  delay(50);
  digitalWrite(stp, LOW);
  delay(25);
  Serial.println(a);

  }

else 
  { 
  digitalWrite(dir, HIGH);
  a++;
  digitalWrite(stp, HIGH);
  delay(10);
  digitalWrite(stp, LOW);
  delay(10);
  Serial.println(a);
  if (a>500) // вращение на 200 шагов в направлении 2

    {
    a = 0;
    digitalWrite(dir, LOW);
    }

  }

}
