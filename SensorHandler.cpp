#include "SensorHandler.h"
#define DHTPIN 5
#define DHTTYPE DHT11
#define SOIL_SENSOR_PIN A0

DHT dht(DHTPIN, DHTTYPE);

void initSensors() {
    dht.begin();
}

int readSoilMoisture() {
    int sensorValue = analogRead(SOIL_SENSOR_PIN);
    int moisturePercent = map(sensorValue, 1023, 0, 0, 100);
    return constrain(moisturePercent, 0, 100);
}

float readTemperature() {
    float temp = dht.readTemperature();
    return isnan(temp) ? -1 : temp;
}

float readHumidity() {
    float hum = dht.readHumidity();
    return isnan(hum) ? -1 : hum;
}
