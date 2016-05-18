#include <cstdio>
#include "xel/xel.h"
#include "g2/g2.h"

void OnAfterGL() {
    printf( "On After GL\n" );
    g2_init();
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
    g2_clear();

    g2_color(128,0,0);
    g2_rect(G2_COLOR,10,10,800,600);

    g2_color(0,128,0);
    g2_rect(G2_COLOR,100,100,800,600);

    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            g2_text(i,j,"hello", 14);
}

int main() {

    xel_init();

    xel_callback( OnAfterGL, OnBeforeGL, OnTick, OnKey, OnMouseMove, OnMouseButton );

    xel_loop();

    xel_uninit();

    return 0;
}
