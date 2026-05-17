#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>

#define BMI160_ADDR 0x69

const char* ssid = "EmilYy";
const char* password = "innerln.y";

WiFiServer server(80);

void writeRegister(uint8_t reg, uint8_t value) {

    Wire.beginTransmission(BMI160_ADDR);

    Wire.write(reg);

    Wire.write(value);

    Wire.endTransmission();
}

int16_t read16(uint8_t reg) {

    Wire.beginTransmission(BMI160_ADDR);

    Wire.write(reg);

    Wire.endTransmission(false);

    Wire.requestFrom(BMI160_ADDR, 2);

    if (Wire.available() < 2) {

        return 0;
    }

    uint8_t lsb = Wire.read();

    uint8_t msb = Wire.read();

    return (int16_t)((msb << 8) | lsb);
}

void setup() {

    Serial.begin(115200);

    delay(3000);

    Serial.println("BOOT");

    Wire.begin(10, 11);

    Serial.println("BMI160 START");

    // accel normal mode
    writeRegister(0x7E, 0x11);

    delay(100);

    Serial.println("CONNECTING WIFI");

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {

        delay(500);

        Serial.print(".");
    }

    Serial.println();

    Serial.println("WIFI CONNECTED");

    Serial.print("ESP IP: ");

    Serial.println(WiFi.localIP());

    server.begin();

    Serial.println("TCP SERVER STARTED");
}

void loop() {

    static WiFiClient client;

    if (!client || !client.connected()) {

        client = server.available();
    }

    int16_t forwardBackward = read16(0x12);

    int16_t leftRight = read16(0x14);

    int16_t upDown = read16(0x16);

    String data =
        String(forwardBackward) + "," +
        String(leftRight) + "," +
        String(upDown);

    Serial.println(data);

    if (client && client.connected()) {

        client.println(data);
    }

    delay(200);
}