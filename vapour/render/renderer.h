#pragma once

#include "../core/ecs.h"
#include "../core/math.h"
#include "../core/gl.h"

namespace vapour {
	namespace render {
		class Renderer {
		public:
			Renderer();
			~Renderer();

			static Renderer* declare() {
					static Renderer renderer;
					return &renderer;
			}
		};
	}
}