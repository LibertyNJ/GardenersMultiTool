#include "config.h"
#include "src/Mode/Mode.h"
#include "src/Mode/SoilMoistureMode.h"

Display *display{nullptr};
Mode *mode{nullptr};
unsigned long previousUpdateMillisecondsElapsed{0};
bool previousModeChangeButtonIsPressed{false};

void setup()
{
	display = new Display{};
	mode = new SoilMoistureMode{display};
	pinMode(dhtSensorPin, INPUT);
	pinMode(modeChangePin, INPUT);
}

void loop()
{
	bool modeChangeButtonIsPressed{digitalRead(modeChangePin)};

	if (modeChangeButtonIsPressed && modeChangeButtonIsPressed != previousModeChangeButtonIsPressed)
		mode->change();

	unsigned long millisecondsElapsed{millis()};

	if (millisecondsElapsed - previousUpdateMillisecondsElapsed >= millisecondUpdateInterval)
	{
		mode->update();
		previousUpdateMillisecondsElapsed = millisecondsElapsed;
	}

	previousModeChangeButtonIsPressed = modeChangeButtonIsPressed;
}
