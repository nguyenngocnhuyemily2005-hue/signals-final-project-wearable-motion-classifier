#include <Arduino.h>
#include <Wire.h>
#include <DFRobot_BMI160.h>

DFRobot_BMI160 bmi160;
int8_t rslt = BMI160_OK;

int16_t accelGyro[6] = {0};

void setup() {

    Serial.begin(115200);

    delay(2000);

    Wire.begin(8, 9);

    rslt = bmi160.I2cInit();

    if (rslt != BMI160_OK) {

        Serial.println("BMI160 initialization failed!");

        while (1);
    }

    Serial.println("BMI160 connected!");
}

void loop() {

    // Read BMI160 data
    bmi160.getAccelGyroData(accelGyro);

    // Timestamp
    unsigned long timestamp = millis();

    // CSV format
    Serial.print(timestamp);
    Serial.print(",");

    Serial.print(accelGyro[0]);
    Serial.print(",");

    Serial.print(accelGyro[1]);
    Serial.print(",");

    Serial.print(accelGyro[2]);
    Serial.print(",");

    Serial.print(accelGyro[3]);
    Serial.print(",");

    Serial.print(accelGyro[4]);
    Serial.print(",");

    Serial.println(accelGyro[5]);

    delay(10);
}