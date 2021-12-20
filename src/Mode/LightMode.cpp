#include "LightMode.h"
#include "../../config.h"
#include "Mode.h"
#include "SoilMoistureMode.h"
#include <Arduino.h>

LightMode::LightMode(Display *display) : Mode{display}
{
	display->setTitle("Light:");
}

void LightMode::change() const
{
	setMode(new SoilMoistureMode{display});
}

void LightMode::update() const
{
	int sensorValue{analogRead(lightSensorPin)};
	String message{mapSensorValueToMessage(sensorValue)};
	display->setMessage(message);
}

String LightMode::mapSensorValueToMessage(int sensorValue) const
{
	if (sensorValue == 0)
		return "Dark       ";
	else if (sensorValue < 200)
		return "Very dim   ";
	else if (sensorValue < 400)
		return "Dim        ";
	else if (sensorValue < 600)
		return "Moderate   ";
	else if (sensorValue < 800)
		return "Bright     ";
	else if (sensorValue < 1000)
		return "Very bright";
	else
		return "Direct     ";
}
