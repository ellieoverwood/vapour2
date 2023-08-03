#include "../core/window.h"
#include "startup.h"

using namespace vapour;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{

	Context ctx;

	vapour::setup(&ctx);

	while (ctx.on) {
		vapour::update(&ctx);
	}
}