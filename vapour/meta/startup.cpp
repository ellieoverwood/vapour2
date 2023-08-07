#include "../core/window.h"
#include "../core/console.h"
#include "startup.h"

using namespace vapour;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	vapour::setup();

	while (vapour::context.on) {
		vapour::update();
	}
}

int main() {
	vapour::console::log(1, "Starting vapour in headless mode");
	vapour::console::blank();

	vapour::setup();

	while (vapour::context.on) {
		vapour::update();
	}
}