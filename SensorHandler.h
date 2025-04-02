#ifndef SENSOR_HANDLER_H
#define SENSOR_HANDLER_H

#include <DHT.h>

void initSensors();
int readSoilMoisture();
float readTemperature();
float readHumidity();

#endif
