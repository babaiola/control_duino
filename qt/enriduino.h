#ifndef ENRIDUINO_H
#define ENRIDUINO_H

#include "enriduino_global.h"
#include "qextserialport/src/qextserialport.h"

#define HIGH 1
#define LOW 0
#define INPUT 1
#define OUTPUT 2

class ENRIDUINOSHARED_EXPORT Enriduino {
public:

    Enriduino();

    ~Enriduino();


    int pin_state[100];

    int analog_state[20];

    int begin(const char *_port_name, BaudRateType _baud);

    void close();

    void digitalWrite(int _pin, int _state);

    int digitalRead(int _pin);

    void pinMode(int _pin, int _mode);

    void analogWrite(int _pin, int _value);

    int analogRead(int _pin);

    void defineServo(int _pin);

    void servoWrite(int _pin, int _value);

private:
    QextSerialPort* _port;

};

#endif // ENRIDUINO_H
