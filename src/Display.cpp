#include "Display.h"
#include "../config.h"
#include <Arduino.h>
#include <LiquidCrystal.h>

Display::Display()
	: lcd{new LiquidCrystal{
		  lcdRegisterSelectPin,
		  lcdEnablePin,
		  lcdDataPin4,
		  lcdDataPin5,
		  lcdDataPin6,
		  lcdDataPin7}}
{
	lcd->begin(lcdColumnCount, lcdRowCount);
}

Display::~Display()
{
	if (lcd != nullptr)
		delete lcd;
}

void Display::clear() const
{
	lcd->clear();
}

void Display::setMessage(const String &message) const
{
	lcd->setCursor(0, 1);
	lcd->print(message);
}

void Display::setTitle(const String &title) const
{
	lcd->setCursor(0, 0);
	lcd->print(title);
}
