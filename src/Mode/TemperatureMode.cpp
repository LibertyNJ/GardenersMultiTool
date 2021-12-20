#include "TemperatureMode.h"
#include "../../config.h"
#include "HumidityMode.h"
#include "Mode.h"
#include <Arduino.h>
#include <DHT.h>

TemperatureMode::TemperatureMode(Display *display)
	: Mode{display}, dht{new DHT{dhtSensorPin, dhtSensorType}}
{
	dht->begin();
	display->setTitle("Temperature:");
}

TemperatureMode::~TemperatureMode()
{
	if (dht != nullptr)
		delete dht;
}

void TemperatureMode::change() const
{
	setMode(new HumidityMode{display});
}

void TemperatureMode::update() const
{
	float sensorValue{dht->readTemperature(temperatureIsFahrenheit)};
	String message{mapSensorValueToMessage(sensorValue)};
	display->setMessage(message);
}

String TemperatureMode::mapSensorValueToMessage(float sensorValue) const
{
	return String{sensorValue, temperatureDecimalPlaces} 
		+ (temperatureIsFahrenheit ? " degrees F    " : " degrees C    ");
}
