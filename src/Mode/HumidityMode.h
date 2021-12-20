#ifndef GARDENERS_MULTI_TOOL_HUMIDITY_MODE_H
#define GARDENERS_MULTI_TOOL_HUMIDITY_MODE_H

#include "../Display.h"
#include "Mode.h"
#include <Arduino.h>
#include <DHT.h>

class HumidityMode final : public Mode
{
public:
	HumidityMode(Display *display);
	~HumidityMode() override;
	void change() const override;
	void update() const override;

private:
	DHT *dht{nullptr};
	String mapSensorValueToMessage(float sensorValue) const;
};

#endif
