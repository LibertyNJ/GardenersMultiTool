#ifndef GARDENERS_MULTI_TOOL_MODE_H
#define GARDENERS_MULTI_TOOL_MODE_H

#include "../Display.h"

class Mode
{
public:
	Mode(Display *display);
	virtual ~Mode();
	virtual void change() const = 0;
	virtual void update() const = 0;

protected:
	Display *display{nullptr};
};

extern Mode *mode;

void setMode(Mode *newMode);

#endif
