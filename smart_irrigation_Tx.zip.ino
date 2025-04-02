
#include <SPI.h>
#include <LoRa.h>
#include <DHT.h>
#include <Servo.h>
#include "LoRaHandler.h"
#include "SensorHandler.h"
#include "ServoManager.h"
#include "BatteryManager.h"
#define LDR_LEFT A1   
#define LDR_RIGHT A2  
int counter = 0;

void setup() {
    Serial.begin(115200);
    initSensors();
    initLoRa();
    initServo();
}

void loop() {
    int ldrLeftValue = analogRead(LDR_LEFT);
    int ldrRightValue = analogRead(LDR_RIGHT);
    adjustServo(ldrLeftValue, ldrRightValue);  // Function now correctly linked
    int soilMoisturePercent = readSoilMoisture();
    float temp = readTemperature();
    float humidity = readHumidity();    
    adjustServo(ldrLeftValue, ldrRightValue);  // Pass values to function
    int batteryPercentage = getBatteryPercentage();

    String LoRaMessage = String(counter) + "/" + String(soilMoisturePercent) + 
                         "@" + String(temp) + "$" + String(humidity) + "|" + 
                         String(batteryPercentage);

    sendLoRaMessage(LoRaMessage);
    counter++;

    delay(3000);
}
