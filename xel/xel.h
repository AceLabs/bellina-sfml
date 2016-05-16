#ifndef XEL_H
#define XEL_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

using namespace sf;

void xel_init();
void xel_uninit();

void xel_callback( void (*OnAfterGL)(),
                   void (*OnBeforeGLDeleted)(),
                   void (*OnTick)(),
                   void (*OnKey)(bool isKeyDown, Keyboard::Key key),
                   void (*OnMouseMove)(int mouseX, int mouseY),
                   void (*OnMouseButton)(bool isButtonDown, int x, int y, Mouse::Button button) );

void xel_loop();

#endif
