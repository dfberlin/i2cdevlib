EXTRA_FLAGS = -D I2CDEV_IMPLEMENTATION=I2CDEV_LINUX_LIBI2C_DEV -D LINUX
EXTRA_FLAGS = -D I2CDEV_IMPLEMENTATION=I2CDEV_LINUX_LIBI2C_DEV -D LINUX -D DEBUG -D I2CDEV_SERIAL_DEBUG

all: bla demo_dmp demo_raw

I2Cdev.o: I2Cdev.cpp
	$(CXX) $(EXTRA_FLAGS) -O -c I2Cdev.cpp
MPU6050.o: MPU6050.cpp
	$(CXX) $(EXTRA_FLAGS) -O -c MPU6050.cpp
arduinoCompat.o: arduinoCompat.cpp arduinoCompat.h
	$(CXX) $(EXTRA_FLAGS) -O -c arduinoCompat.cpp

test.o: test.cpp
	$(CXX) $(EXTRA_FLAGS) -O -c test.cpp
demo_dmp.o: demo_dmp.cpp
	$(CXX) $(EXTRA_FLAGS) -O -c demo_dmp.cpp
demo_raw.o: demo_raw.cpp
	$(CXX) $(EXTRA_FLAGS) -O -c demo_raw.cpp



bla: I2Cdev.o MPU6050.o arduinoCompat.o test.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o test.o -O -o bla

demo_raw: I2Cdev.o MPU6050.o arduinoCompat.o demo_raw.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o demo_raw.o -O -o demo_raw
demo_dmp: I2Cdev.o MPU6050.o arduinoCompat.o demo_dmp.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o demo_dmp.o -O -o demo_dmp 

clean:
	rm -f *.o demo_dmp demo_raw bla
	
