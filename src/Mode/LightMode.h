#ifndef GARDENERS_MULTI_TOOL_LIGHT_MODE_H
#define GARDENERS_MULTI_TOOL_LIGHT_MODE_H

#include "../Display.h"
#include "Mode.h"
#include <Arduino.h>

class LightMode final : public Mode
{
public:
	LightMode(Display *display);
	void change() const override;
	void update() const override;

private:
	String mapSensorValueToMessage(int sensorValue) const;
};

#endif
