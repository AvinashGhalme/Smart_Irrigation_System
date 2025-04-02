#include "ServoManager.h"  // Include the header file

#define SERVO_PIN 4  // Define the servo pin
Servo solarServo;
int servoPosition = 90;  // Initial position

void initServo() {
    solarServo.attach(SERVO_PIN);
    solarServo.write(servoPosition);
}

void adjustServo(int ldrLeftValue, int ldrRightValue) {
    if (ldrLeftValue > ldrRightValue + 50) {  
        if (servoPosition > 0) {
            servoPosition -= 10;
            solarServo.write(servoPosition);
        }
    } else if (ldrRightValue > ldrLeftValue + 50) {
        if (servoPosition < 180) {
            servoPosition += 10;
            solarServo.write(servoPosition);
        }
    }
}
