#ifndef GARDENERS_MULTI_TOOL_TEMPERATURE_MODE_H
#define GARDENERS_MULTI_TOOL_TEMPERATURE_MODE_H

#include "../Display.h"
#include "Mode.h"
#include <Arduino.h>
#include <DHT.h>

class TemperatureMode final : public Mode
{
public:
	TemperatureMode(Display *display);
	~TemperatureMode() override;
	void change() const override;
	void update() const override;

private:
	DHT *dht{nullptr};
	String mapSensorValueToMessage(float sensorValue) const;
};

#endif
