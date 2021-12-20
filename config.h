#ifndef GARDENERS_MULTI_TOOL_CONFIG_H
#define GARDENERS_MULTI_TOOL_CONFIG_H

#include <Arduino.h>
#include <DHT.h>

const uint8_t dhtSensorPin{8};
const uint8_t lcdDataPin4{5};
const uint8_t lcdDataPin5{4};
const uint8_t lcdDataPin6{3};
const uint8_t lcdDataPin7{2};
const uint8_t lcdEnablePin{11};
const uint8_t lcdRegisterSelectPin{12};
const uint8_t lightSensorPin{A0};
const uint8_t modeChangePin{7};
const uint8_t soilMoistureSensorPin{A1};

const unsigned long millisecondUpdateInterval{1000};

const int soilMoistureMaxPercentage{100};
const int soilMoistureMinPercentage{0};
const int soilMoistureSensorDryValue{425};
const int soilMoistureSensorWetValue{210};

const uint8_t dhtSensorType{DHT11};
const uint8_t humidityDecimalPlaces{1};
const uint8_t temperatureDecimalPlaces{1};
const bool temperatureIsFahrenheit{true};

const uint8_t lcdColumnCount{16};
const uint8_t lcdRowCount{2};

#endif
