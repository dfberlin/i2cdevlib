/*
 * This is wrapper around Arduinos original MPU6050_DMP6.ino file.
 * I want to change as few as possible on the arduino sources in
 * order to have my Linux port running.
 * 
 * In my imagination this will lead to a scenario where both worlds
 * can actually benefit from each other.
 *
 * This code is copyright by Dirk Fleischer.
 */

#include <iostream>
#include "I2Cdev.h"
// For Arduino compatibiliy ...
//#include "arduinoCompat.h"
arduinoSerial Serial;

#include "MPU6050_DMP6.ino" // Yes including code is ugly - but I have no choice ;)

int main() {
    int status;
    int bus_nr = 1;
    status = I2Cdev::openBus(bus_nr);
    if (status == 0) {
        std::cout << "Successfully opened bus: " << bus_nr << std::endl; 
    } else {
        std::cout << "Hmmm ... we have some problems ..." << std::endl;
        std::cout << errno << " " << strerror(errno) << std::endl;
    }

    setup();
    while(true) {
        loop();
    }
}
