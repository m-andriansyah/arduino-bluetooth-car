#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo1;
SoftwareSerial BT(0, 1);
char perintah;
int motor1 = 5;
int motor2 = 6;
int motor3 = 9;
int motor4 = 10;
int i;

void setup(){ 
  BT.begin(9600);
  BT.print("$$$");
  delay(100);
  BT.println("U,9600,N");
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  servo1.attach(12);
  servo1.write(0);
}

void loop(){
  if (BT.available()){
    
    char c = (char) BT.read();
    BT.print(c);

      if(c == 'F')
      {
        maju();
      }
      if(c == 'R')
      {
        kanan();
      }
      if(c == 'B')
      {
        mundur();
      }
      if(c == 'L')
      {
        kiri();
      }
      if(c == 'I')
      {
        majukanan();
      }
      if(c == 'J')
      {
        mundurkanan();
      }
      if(c == 'H')
      {
        mundurkiri();
      }
      if(c == 'G')
      {
        majukiri();
      }
      if(c == 'U')
      {
        atas();
      }
      if(c == 'D')
      {
        bawah();
      }
      if(c == 'S')
      {
        berhenti();
      }
    
}
}

void maju(){
  analogWrite(motor1,255);
  digitalWrite(motor2,LOW);
  analogWrite(motor3,255);
  digitalWrite(motor4,LOW);
}

void kanan(){
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  analogWrite(motor3,255);
  digitalWrite(motor4,LOW);
}
void kiri(){
  analogWrite(motor1,255);
  digitalWrite(motor2,LOW);
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,LOW);
}
void mundur(){
  digitalWrite(motor1,LOW);
  analogWrite(motor2,255);
  digitalWrite(motor3,LOW);
  analogWrite(motor4,255);
}
void majukanan(){
  analogWrite(motor1,100);
  digitalWrite(motor2,LOW);
  analogWrite(motor3,255);
  digitalWrite(motor4,LOW);
}
void mundurkanan(){
  digitalWrite(motor1,LOW);
  analogWrite(motor2,100);
  digitalWrite(motor3,LOW);
  analogWrite(motor4,255);
}
void mundurkiri(){
  digitalWrite(motor1,LOW);
  analogWrite(motor2,255);
  digitalWrite(motor3,LOW);
  analogWrite(motor4,100);
}
void majukiri(){
  analogWrite(motor1,255);
  digitalWrite(motor2,LOW);
  analogWrite(motor3,100);
  digitalWrite(motor4,LOW);
}
void berhenti(){
  digitalWrite(motor1,LOW);
  digitalWrite(motor2,LOW);
  digitalWrite(motor3,LOW);
  digitalWrite(motor4,LOW);
}

void atas(){
    i = servo1.read();
    for (i; i<=180; i++){
      servo1.write(i);
      char bt = BT.read();
      if (bt == 'u'){
            i=181;
      }
      delay(200);
    }
  
}

void bawah(){
    i = servo1.read();
    for (i; i>0; i--){
      servo1.write(i);
      char bt = BT.read();
      if (bt == 'd'){
            i=0;
      }
      delay(200);
    }
  
}
