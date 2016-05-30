EXTRA_FLAGS = -D I2CDEV_IMPLEMENTATION=I2CDEV_LINUX_LIBI2C_DEV -D LINUX -Wall
#EXTRA_FLAGS = -D I2CDEV_IMPLEMENTATION=I2CDEV_LINUX_LIBI2C_DEV -D LINUX -D DEBUG -D I2CDEV_SERIAL_DEBUG -Wall

OPTIMIZE = -O3 

ARDUINO_MPU6050_DIR = ../../Arduino/MPU6050

all: bla demo_dmp demo_raw

MPU6050.cpp: $(ARDUINO_MPU6050_DIR)/MPU6050.cpp
	ln -s  $(ARDUINO_MPU6050_DIR)/MPU6050.cpp .

MPU6050.h: $(ARDUINO_MPU6050_DIR)/MPU6050.h
	ln -s  $(ARDUINO_MPU6050_DIR)/MPU6050.h .

MPU6050_6Axis_MotionApps20.h: $(ARDUINO_MPU6050_DIR)/MPU6050_6Axis_MotionApps20.h
	ln -s  $(ARDUINO_MPU6050_DIR)/MPU6050_6Axis_MotionApps20.h .

helper_3dmath.h: $(ARDUINO_MPU6050_DIR)/helper_3dmath.h
	ln -s  $(ARDUINO_MPU6050_DIR)/helper_3dmath.h .

I2Cdev.o: I2Cdev.cpp
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c I2Cdev.cpp
MPU6050.o: MPU6050.cpp MPU6050.h MPU6050_6Axis_MotionApps20.h helper_3dmath.h
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c MPU6050.cpp

arduinoCompat.o: arduinoCompat.cpp arduinoCompat.h
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c arduinoCompat.cpp

test.o: test.cpp
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c test.cpp
demo_dmp.o: demo_dmp.cpp
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c demo_dmp.cpp
demo_raw.o: demo_raw.cpp
	$(CXX) $(EXTRA_FLAGS) $(OPTIMIZE) -c demo_raw.cpp



bla: I2Cdev.o MPU6050.o arduinoCompat.o test.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o test.o -O -o bla

demo_raw: I2Cdev.o MPU6050.o arduinoCompat.o demo_raw.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o demo_raw.o -O -o demo_raw
demo_dmp: I2Cdev.o MPU6050.o arduinoCompat.o demo_dmp.o
	$(CXX) $(EXTRA_FLAGS) I2Cdev.o MPU6050.o arduinoCompat.o demo_dmp.o -O -o demo_dmp 

clean:
	rm -f *.o demo_dmp demo_raw bla
	# No worries ... these are just the symlinks :)
	rm -f MPU6050_6Axis_MotionApps20.h MPU6050.cpp MPU6050.h helper_3dmath.h
	
