#include "SoilMoistureMode.h"
#include "../../config.h"
#include "Mode.h"
#include "TemperatureMode.h"
#include <Arduino.h>

SoilMoistureMode::SoilMoistureMode(Display *display) : Mode{display}
{
	display->setTitle("Soil moisture:");
}

void SoilMoistureMode::change() const
{
	setMode(new TemperatureMode{display});
}

void SoilMoistureMode::update() const
{
	int sensorValue{analogRead(soilMoistureSensorPin)};
	String message{mapSensorValueToMessage(sensorValue)};
	display->setMessage(message);
}

String SoilMoistureMode::mapSensorValueToMessage(int sensorValue) const
{
	int moisturePercentage{map(
		sensorValue,
		soilMoistureSensorDryValue,
		soilMoistureSensorWetValue,
		soilMoistureMinPercentage,
		soilMoistureMaxPercentage)};

	if (moisturePercentage >= 100)
		return "100%";
	else if (moisturePercentage <= 0)
		return "0%  ";
	else
		return String{moisturePercentage, DEC} + "%  ";
}
