#pragma once

#include "../core/ecs.h"
#include "../core/math.h"
#include "../core/gl.h"

namespace vapour {
	namespace render {
		class Renderer {
		public:
			Renderer(vapour::Context* ctx);
			~Renderer();

			static Renderer* get(Context* ctx) {
					static Renderer renderer(ctx);
					return &renderer;
			}
		private:
			Context* ctx;
		};
	}
}