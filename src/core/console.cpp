#include "console.h"

#include <cstdarg>

using namespace vapour::core;

void console::breakpoint() {
	printf("| breakpoint tripped\n");
}

void console::breakpoint(char c) {
	printf("| breakpoint [%c] tripped\n", c);
}

void console::blank() {
	printf("\n");
}

void console::log(int size, ...) {
	va_list args;
	va_start(args, size);

	for (int i = 0; i < size; i ++) {
		const char* line = va_arg(args, const char*);
		if (line[0] == EOF) break;

		printf("%s ", line);
	}

	va_end(args);
	printf("\n");
}