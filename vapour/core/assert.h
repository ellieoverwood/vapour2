#pragma once
#include "../wrapper/popup.h"

#define VAPOUR_ASSERT(expr, title, content) {\
	if (!(expr)) {vapour::popup::error(title, content);}\
}

#define VAPOUR_ASSERTF(expr, title, content) {\
	if (!(expr)) {vapour::popup::error(title, content); return NULL;}\
}