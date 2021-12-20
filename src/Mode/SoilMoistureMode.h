#ifndef GARDENERS_MULTI_TOOL_SOIL_MOISTURE_MODE_H
#define GARDENERS_MULTI_TOOL_SOIL_MOISTURE_MODE_H

#include "../Display.h"
#include "Mode.h"
#include <Arduino.h>

class SoilMoistureMode final : public Mode
{
public:
	SoilMoistureMode(Display *display);
	void change() const override;
	void update() const override;

private:
	String mapSensorValueToMessage(int sensorValue) const;
};

#endif
