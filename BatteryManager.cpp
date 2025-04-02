#include <Arduino.h>  // Include Arduino core functions
#include "BatteryManager.h"

#define BATTERY_PIN A3
const float MinBatteryVoltage = 3.0;
const float MaxBatteryVoltage = 4.2;

int getBatteryPercentage() {
    float batteryVoltage = analogRead(BATTERY_PIN) * (5.0 / 1023.0);
    int percentage = map(batteryVoltage * 1000, MinBatteryVoltage * 1000, MaxBatteryVoltage * 1000, 0, 100);
    return constrain(percentage, 0, 100);
}
