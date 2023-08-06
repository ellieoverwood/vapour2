#include "../core/window.h"
#include "startup.h"

using namespace vapour;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	vapour::context = vapour::ecs::Context();

	vapour::setup();

	while (vapour::context.on) {
		vapour::update();
	}
}