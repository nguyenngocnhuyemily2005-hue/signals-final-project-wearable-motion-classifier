#include <Arduino.h>
#include <Wire.h>

#define BMI160_ADDR 0x69

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

    uint8_t lsb = Wire.read();

    uint8_t msb = Wire.read();

    return (int16_t)((msb << 8) | lsb);
}

void setup() {

    Serial.begin(115200);

    delay(3000);

    Wire.begin(10, 11);

    Serial.println("BMI160 START");

    // accel normal mode
    writeRegister(0x7E, 0x11);

    delay(100);
}

void loop() {

    int16_t forwardBackward = read16(0x12);

    int16_t leftRight = read16(0x14);

    int16_t upDown = read16(0x16);

    Serial.print("FB = ");
    Serial.print(forwardBackward);

    Serial.print(" | LR = ");
    Serial.print(leftRight);

    Serial.print(" | UD = ");
    Serial.println(upDown);

    delay(200);
}