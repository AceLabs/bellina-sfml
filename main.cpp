#include <cstdio>
#include "xel/xel.h"

void OnAfterGL() {
    printf( "On After GL\n" );
}

void OnBeforeGL() {
    printf( "On Before GL\n" );
}

void OnMouseMove(int x, int y) {
    //printf( "mouse moved %i %i\n", x, y );
}

void OnMouseButton(bool isButtonDown, int x, int y, Mouse::Button button) {
    printf( "mouse button %i %i %i\n", isButtonDown, x, y );
}

void OnKey(bool isDown, sf::Keyboard::Key key) {
    sf::Keyboard::Key k;

    printf( "key %i\n", key == sf::Keyboard::Key::A );
}

void OnTick() {
    //printf( "on tick\n" );
}

int main() {

    xel_init();

    xel_callback( OnAfterGL, OnBeforeGL, OnTick, OnKey, OnMouseMove, OnMouseButton );

    xel_loop();

    xel_uninit();

    return 0;
}
