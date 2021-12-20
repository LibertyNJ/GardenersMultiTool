#include "Mode.h"
#include "../Display.h"

Mode::Mode(Display *display) : display{display}
{
	display->clear();
};

Mode::~Mode() {}

void setMode(Mode *newMode)
{
	if (mode != nullptr)
		delete mode;

	mode = newMode;
}
