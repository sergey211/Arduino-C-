int mr1=4;  //motor right 1
int mr2=5;  //motor right 2
int ml1=6; //motor left 1
int ml2=7; //motor left 2

void setup() {
pinMode(mr1,OUTPUT);
pinMode(mr2,OUTPUT);
pinMode(ml1,OUTPUT);
pinMode(ml2,OUTPUT);
}

void loop() {
stop();
delay(1000);
forward();
delay(1000);
stop();
backward();
delay(1000);
}

void forward()
 {
  digitalWrite(mr1,HIGH);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,HIGH);
  digitalWrite(ml2,LOW);
 } 

void backward()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,HIGH);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,HIGH);
 }

void stop()
 {
  digitalWrite(mr1,LOW);
  digitalWrite(mr2,LOW);
  digitalWrite(ml1,LOW);
  digitalWrite(ml2,LOW);
 }

