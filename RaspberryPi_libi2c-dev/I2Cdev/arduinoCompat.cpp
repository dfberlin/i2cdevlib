#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include "arduinoCompat.h"

/**
 * Linux implementation of Arduinos millis() function.
 * @return miliseconds since some point in time.
 **/

uint32_t millis() {
    static struct timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return (time.tv_sec * 1000) + (time.tv_nsec / 1000000);
}

/**
 * Partial fake Serial implementation to gain compatibility with
 * arduino style debug messages.
 * Create a global instance named Serial to use it.
 **/

arduinoSerial::arduinoSerial() {
}

void arduinoSerial::print(int value, enum arduinoFormatINT format) {
    switch (format) {
        case DEC:
            printf("%d", value);
            break;
        case HEX:
            printf("%X", value);
            break;
        case OCT:
            printf("%o", value);
            break;
        default:
            // Binary not implemented ... so hex is the best bet.
            printf("%x", value);
            break;
    }
}

void arduinoSerial::println(int value, enum arduinoFormatINT format) {
    print(value, format);
    printf("\n");
}

void arduinoSerial::print(double value, int digitsAfterDot) {
    printf("%.*f", digitsAfterDot, value);
}

void arduinoSerial::println(double value, int digitsAfterDot) {
    print(value, digitsAfterDot);
    printf("\n");
}

void arduinoSerial::print(const char * value) {
    printf("%s", value);
}

void arduinoSerial::println(const char *value) {
    print(value);
    printf("\n");
}

void arduinoSerial::print(const char value) {
    printf("%c", value);
}

void arduinoSerial::println(const char value) {
    print(value);
    printf("\n");
}
