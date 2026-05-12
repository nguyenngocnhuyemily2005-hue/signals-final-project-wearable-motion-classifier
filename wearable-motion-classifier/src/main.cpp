#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    delay(2000);

    Serial.println("ESP32 STARTED");
}

void loop() {
    Serial.println("hello esp32");
    delay(1000);
}