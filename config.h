#ifndef GARDENERS_MULTI_TOOL_CONFIG_H
#define GARDENERS_MULTI_TOOL_CONFIG_H

#include <Arduino.h>
#include <DHT.h>

constexpr uint8_t dhtSensorPin{8};
constexpr uint8_t lcdDataPin4{5};
constexpr uint8_t lcdDataPin5{4};
constexpr uint8_t lcdDataPin6{3};
constexpr uint8_t lcdDataPin7{2};
constexpr uint8_t lcdEnablePin{11};
constexpr uint8_t lcdRegisterSelectPin{12};
constexpr uint8_t lightSensorPin{A0};
constexpr uint8_t modeChangePin{7};
constexpr uint8_t soilMoistureSensorPin{A1};

constexpr unsigned long millisecondUpdateInterval{1000};

constexpr int soilMoistureMaxPercentage{100};
constexpr int soilMoistureMinPercentage{0};
constexpr int soilMoistureSensorDryValue{425};
constexpr int soilMoistureSensorWetValue{210};

constexpr uint8_t dhtSensorType{DHT11};
constexpr uint8_t humidityDecimalPlaces{1};
constexpr uint8_t temperatureDecimalPlaces{1};
constexpr bool temperatureIsFahrenheit{true};

constexpr uint8_t lcdColumnCount{16};
constexpr uint8_t lcdRowCount{2};

#endif
