# vapour
A lightweight, optimized C++ game engine built with no external libraries.

## Platforms
Vapour currently supports Windows, with UNIX support in the forseeable future. 

## Compile Instructions
Use the precombiled .lib file found in /build, or compile your own in Visual Studio. Include the headers.

## Example Usage
```cpp
#include <vapour/include.h>
#include <vapour/render/renderer.h>

using namespace vapour;
using namespace vapour::math;
using namespace vapour::render;

Renderer* renderer;
entity object;

void vapour::setup() {
    Transform::declare();
    renderer = Renderer::declare();

    object = entity::spawn();
    object.add<Transform>()->position.x = 3;
}

void vapour::main() {
    renderer->clear();
    renderer->render();
}
```
