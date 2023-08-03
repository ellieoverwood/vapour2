#include "gl.h"

using namespace vapour;
static HMODULE opengl32;

void* gl::load_func(const char* name) {
    void* p = (void*)wglGetProcAddress(name);
    if (p == 0 ||
        (p == (void*)0x1) || (p == (void*)0x2) || (p == (void*)0x3) ||
        (p == (void*)-1))
    {
        p = (void*)GetProcAddress(opengl32, name);
    }

    return p;
}

void gl::load() {
    opengl32 = LoadLibraryA("opengl32.dll");
    gl::__autogen_load_all();
}