#include "enriduino.h"
#include<stdio.h>
#include<math.h>
Enriduino::Enriduino()
{
}

Enriduino::~Enriduino()
{

}

//open port
int Enriduino::begin(const char *_port_name, BaudRateType _baud){
    _port = new QextSerialPort( _port_name, QextSerialPort::EventDriven);
    if(_port->open(QIODevice::ReadWrite)){
            _port->setBaudRate(_baud);
            _port->setFlowControl(FLOW_XONXOFF);
            _port->setParity(PAR_NONE);
            _port->setDataBits(DATA_8);
            _port->setStopBits(STOP_1);
            _port->setDtr(false);
            _port->setTimeout(100);
            return 1;
    } return 0;
}

//close port
void Enriduino::close(){
    _port->close();
}


//pin state

void Enriduino::digitalWrite(int _pin, int _state){
    const char pino[4] = {'W', (_pin+48), (_state+48), '~'};
    _port->write(pino, 4);
}

//pin mode
void Enriduino::pinMode(int _pin, int _mode){
    const char pino[4] = {'P', (_pin+48), (_mode+48), '~'};
    _port->write(pino, 4);
}

//digitalRead
int Enriduino::digitalRead(int _pin){
    int x, s;
    char data[2];
    const char pino[3] = {'R', (_pin+48), '~'};
    _port->write(pino, 3);

    long count;
    count = time(NULL)+1;

    while((count-time(NULL))>0){
    if ((x = _port->bytesAvailable()) > 1){
      s =  _port->read(data, x);
      if (data[0] == 'r')
          pin_state[_pin] = (int)data[1]-48;
      if (s!= -1)
                  data[x] = '\0';
              else
                  data[0] = '\0';
      break;
    }}
    return pin_state[_pin];
}


//analogWrite
void Enriduino::analogWrite(int _pin, int _value){
    const  char pino[6] = {'A', (_pin+48), (_value/100)+48, ((_value/10)%10)+48, (_value%10)+48, '~' };
    _port->write(pino, 6);
}

//analogRead
int Enriduino::analogRead(int _pin){
    int x, s;
    char data[5];
    const  char pino[3] = {'N', _pin+48, '~'};
    _port->write(pino, 3);

    long count;
    count = time(NULL)+1;

    while((count-time(NULL))>0){
    if ((x = _port->bytesAvailable()) > 4){
      s =  _port->read(data, x);
      if (data[0] == 'n')
          analog_state[_pin] = 0;
          for (int i = 1; i< 5; i++)
              analog_state[_pin] += (data[i]-48)*(pow(10, 4-i));
      if (s!= -1)
                  data[x] = '\0';
              else
                  data[0] = '\0';
      break;
    }}
    return analog_state[_pin];
}

//define servo
void Enriduino::defineServo(int _pin){
    const char pino[3] = {'S', _pin+48, '~'};
    _port->write(pino, 3);
}

//servo write
void Enriduino::servoWrite(int _pin, int _value){
    const  char pino[6] = {'M', (_pin+48), (_value/100)+48, ((_value/10)%10)+48, (_value%10)+48, '~' };
    _port->write(pino, 6);
}
