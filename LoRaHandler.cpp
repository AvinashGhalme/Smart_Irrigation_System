#include "LoRaHandler.h"

#define ss 10
#define rst 9
#define dio0 2

void initLoRa() {
    Serial.println("Initializing LoRa...");
    LoRa.setPins(ss, rst, dio0);
    while (!LoRa.begin(433E6)) {
        Serial.println("LoRa initialization failed. Retrying in 5 seconds...");
        delay(5000);
    }
    Serial.println("LoRa initialized successfully.");
}

void sendLoRaMessage(String message) {
    Serial.print("Sending packet: ");
    Serial.println(message);
    
    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
}
