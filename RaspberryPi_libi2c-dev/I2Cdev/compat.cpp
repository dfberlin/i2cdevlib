#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

/**
 * Linux implementation of Arduinos millis() funktion.
 * @return miliseconds since some point in time.
 */

uint32_t millis() {
    static struct timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return (time.tv_sec * 1000) + (time.tv_nsec / 1000000);
}

int main () {
    uint32_t t1 = millis();
    usleep(1000);
    uint32_t t2 = millis();
    printf("t1: %ld\t t2: %ld \t t2 - t1 = %ld\n", t1, t2, t2-t1);
}
