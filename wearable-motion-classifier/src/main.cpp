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

    bmi160.getAccelGyroData(accelGyro);

    Serial.print("AX: ");
    Serial.print(accelGyro[0]);

    Serial.print(" AY: ");
    Serial.print(accelGyro[1]);

    Serial.print(" AZ: ");
    Serial.print(accelGyro[2]);

    Serial.print(" GX: ");
    Serial.print(accelGyro[3]);

    Serial.print(" GY: ");
    Serial.print(accelGyro[4]);

    Serial.print(" GZ: ");
    Serial.println(accelGyro[5]);

    delay(200);
}