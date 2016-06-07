#ifndef COMPAT_H
#define COMPAT_H
#include <unistd.h>
#include <inttypes.h>
#include <math.h>

#define delay(X) usleep(X * 1000)
#define digitalPinToInterrupt(X) 0

uint32_t millis();

enum arduinoFormatINT {
    DEC,
    HEX,
    BIN,
    OCT
};

enum arduinoPinMode {
    INPUT,
    OUTPUT
};

enum arduinoPinInterruptType {
    RISING,
    FALLING
};

void attachInterrupt(int pin, void (*callback)(void), enum arduinoPinInterruptType);

void pinMode(int pin, enum arduinoPinMode mode);
void digitalWrite(int pin, int value);

class arduinoSerial {
    public:

        arduinoSerial();

        void begin(int baud);
        int available(void);
        int read(void);
        bool operator! (void);
        void print(int value, enum arduinoFormatINT format=DEC);
        void print(double value, int digitsAfterDot=2);
        void print(const char * value);
        void print(const char value);

        void println(int value, enum arduinoFormatINT format=DEC);
        void println(double value, int digitsAfterDot=2);
        void println(const char * value);
        void println(const char value);
};
    
#endif
