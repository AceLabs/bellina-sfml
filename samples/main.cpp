#include <cstdio>
#include "../xel/xel.h"
#include "../g2/g2.h"

// #include "MyApp/_obj/_cgo_export.h"

void OnAfterGL() {
    printf( "\n" );
    g2_init();
}

void OnBeforeGL() {
}

void OnMouseMove(int x, int y) {
}

void OnMouseButton(bool isButtonDown, int x, int y, Mouse::Button button) {
}

void OnKey(bool isDown, sf::Keyboard::Key key) {
}

void OnTick() {
    g2_clear();

    g2_color(128,0,0);
    g2_rect(G2_COLOR,10,10,800,600);

    g2_color(0,128,0);
    g2_rect(G2_COLOR,100,100,800,600);

    g2_alpha(12);
    g2_text(G2_ALPHA, 10,10,"hello", 44);
}

int main() {

    xel_init();

    xel_callback( OnAfterGL, OnBeforeGL, OnTick, OnKey, OnMouseMove, OnMouseButton );

    xel_loop();

    xel_uninit();

    return 0;
}
