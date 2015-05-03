#ifndef ENRIDUINO_H
#define ENRIDUINO_H

#include <Arduino.h>
#include <Servo.h>


class Enriduino{

 public:
 
   Enriduino();
  
   void start();
   
 private:

   int i;

   Servo sv[14];
   
   char serial[6];
   
   void Write(); 
   
   void Read();
   
   void pinmode();
  
   void AWrite();
   
   void ARead();
   
   void servo();

   void servoWrite();
   
};

#endif
