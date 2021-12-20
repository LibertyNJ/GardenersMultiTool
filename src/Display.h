#ifndef GARDENERS_MULTI_TOOL_DISPLAY_H
#define GARDENERS_MULTI_TOOL_DISPLAY_H

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display final
{
public:
	Display();
	~Display();
	void clear() const;
	void setMessage(const String &message) const;
	void setTitle(const String &title) const;

private:
	LiquidCrystal *lcd{nullptr};
};

#endif
