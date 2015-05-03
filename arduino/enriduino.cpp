#include "enriduino.h"

Enriduino::Enriduino(){
  i=0;
}

void Enriduino::start(){
  if (Serial.available()){
     serial[i++] = Serial.read();  
  }
  if (serial[i-1]==126){
    i=0;
    pinmode();
    Write();
    Read();
    AWrite();
    ARead();
    servo();
    servoWrite();
  }
}

void Enriduino::Write(){
    if (serial[0] == 87){
      serial[1] -= 48;
      serial[2] -= 48;
    digitalWrite(serial[1], serial[2]);
    }
}

void Enriduino::pinmode(){
    if (serial[0] == 80){ 
      serial[1] -= 48;
      serial[2] -= 48;
    if (serial[2] == 1)
    pinMode(serial[1], INPUT);
    else if (serial[2] == 2)
    pinMode(serial[1], OUTPUT);    
    }  
}

void Enriduino::Read(){
    if (serial[0] == 82){ 
      serial[1] -= 48;
    Serial.write('r');
    Serial.write(digitalRead(serial[1])+48);
    }
}

void Enriduino::AWrite(){
  if (serial[0] == 65){
    serial[1] -= 48;
    serial[2] -= 48;
    serial[3] -= 48;
    serial[4] -= 48;
  analogWrite(serial[1], (serial[2]*100)+(serial[3]*10)+serial[4]);
  }
}

void Enriduino::ARead(){
  if (serial[0] == 78){
    serial[1] -= 48;
    int stat = analogRead(serial[1]);
    Serial.write('n');
    Serial.write(stat/1000+48);
    Serial.write((stat%1000)/100+48);
    Serial.write((stat%100)/10+48);
    Serial.write(stat%10+48);
  }
}

void Enriduino::servo(){
  if (serial[0] == 83){
    serial[1] -= 48;
    sv[serial[1]].attach(serial[1]);
  }
}

void Enriduino::servoWrite(){
  if (serial[0] == 77){
    serial[1] -= 48;
    serial[2] -= 48;
    serial[3] -= 48;
    serial[4] -= 48;
    serial[5] -= 48;
    sv[serial[1]].write((serial[2]*100)+(serial[3]*10)+serial[4]);
  }
}

