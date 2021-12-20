#include "HumidityMode.h"
#include "../../config.h"
#include "LightMode.h"
#include "Mode.h"
#include <Arduino.h>
#include <DHT.h>

HumidityMode::HumidityMode(Display *display)
	: Mode{display}, dht{new DHT{dhtSensorPin, dhtSensorType}}
{
	dht->begin();
	display->setTitle("Humidity:");
}

HumidityMode::~HumidityMode()
{
	if (dht != nullptr)
		delete dht;
}

void HumidityMode::change() const
{
	setMode(new LightMode{display});
}

void HumidityMode::update() const
{
	float sensorValue{dht->readHumidity()};
	String message{mapSensorValueToMessage(sensorValue)};
	display->setMessage(message);
}

String HumidityMode::mapSensorValueToMessage(float sensorValue) const
{
	return String{sensorValue, humidityDecimalPlaces} + "%    ";
}
