#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stropts.h>
#include <poll.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
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

void pinMode(int pin, enum arduinoPinMode mode) {
    // We don't know nothing about any pins.
    // The best we can do is to add some debug logging.
    #ifdef arduinoCompat_DEBUG
        printf("pinMode(%d, %d) called.\n", pin, mode);
    #endif
}

void digitalWrite(int pin, int value) {
    // We don't know nothing about any pins.
    // The best we can do is to add some debug logging.
    #ifdef arduinoCompat_DEBUG
        printf("digitalWrite(%d, %d) called.\n", pin, value);
    #endif
}

void attachInterrupt(int pin, void (*callback)(void), enum arduinoPinInterruptType) {
    // For now, we do nothing here ...
}

/**
 * Partial fake Serial implementation to gain compatibility with
 * arduino style debug messages.
 * Create a global instance named Serial to use it.
 **/

arduinoSerial::arduinoSerial() {
}

void arduinoSerial::begin(int baud) {
    // Just a dummy since we have no serial.
};

int arduinoSerial::available(void) {
    static struct pollfd pfd = {
        .fd = STDIN_FILENO,
        .events = POLLIN,
        .revents = 0
    };
    int retVal = 0;
    if ( poll( &pfd, 1, 0 ) > 0 ) {
            // Acually not absolutely true, but we can
            // guarantee at least one byte to be available.
            retVal = 1;
    }
    return retVal;
}

int arduinoSerial::read(void) {
    return getchar();
}


bool arduinoSerial::operator!(void) {
    // Since we are faking we return always false.
    return false;
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
