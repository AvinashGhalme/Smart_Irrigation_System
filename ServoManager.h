#ifndef SERVO_MANAGER_H
#define SERVO_MANAGER_H

#include <Arduino.h>
#include <Servo.h>

void initServo();
void adjustServo(int ldrLeftValue, int ldrRightValue);

#endif
