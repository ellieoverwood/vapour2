#pragma once

#include "core/ecs.h"
#include "core/math.h"
#include "core/console.h"
#include "meta/startup.h"

/*#include <vapour/include.h>
#include <vapour/render/renderer.h>

using namespace vapour;
using namespace vapour::math;
using namespace vapour::render;

Renderer* renderer;
entity camera;

void vapour::setup() {
    Transform::declare();
    renderer = Renderer::declare();

    camera = entity::spawn();
    camera.add<Transform>();
    camera.get<Transform>()->position.x = 3;
}

void vapour::main() {
    renderer->clear();
    renderer->render();
}*/