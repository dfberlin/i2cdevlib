#ifndef COMPAT_H
#define COMPAT_H
#include <unistd.h>
#include <inttypes.h>

#define delay(X) usleep(X * 1000)
uint32_t millis();

enum arduinoFormatINT {
    DEC,
    HEX,
    BIN,
    OCT
};

class arduinoSerial {
    public:

        arduinoSerial();

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
