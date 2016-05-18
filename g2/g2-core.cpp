#include <SFML/Graphics.hpp>

using namespace sf;

namespace xel { extern RenderWindow* window; };

namespace g2 {

    RenderWindow *window;

    Font font;

    int red, green, blue;
    int alpha;
}

using namespace g2;

unsigned int G2_COLOR = 1 << 0;
unsigned int G2_ALPHA = 1 << 1;

void g2_init() {
    window = xel::window;

    font.loadFromFile("fonts/OpenSans/OpenSans-Bold.ttf");
}

void g2_uninit() {
}

void g2_color(int _red, int _green, int _blue) {
    red = _red;
    green = _green;
    blue = _blue;
}

void g2_alpha(int _alpha) {
    alpha = _alpha;
}

void g2_rect(unsigned int flags, int left, int top, int width, int height) {

    RectangleShape rectangle;

//    if ( !(flags & G2_ALPHA) )
        rectangle.setFillColor(Color(red, green, blue, 255));

//    if (flags & G2_ALPHA)
//        rectangle.setFillColor(Color(red, green, blue, alpha));

    rectangle.setSize(Vector2f(width, height));
//    rectangle.setOutlineColor(Color::Red);
//    rectangle.setOutlineThickness(1);
    rectangle.setPosition(left, top);

    window->draw(rectangle);
}

void g2_text(unsigned int flags, int left, int top, char* text, int size) {
    sf::Text text2(text, font, 11);

    if (flags & G2_ALPHA    )
        text2.setColor(Color(red, green, blue, alpha));
    else
        text2.setColor(Color(red, green, blue, 255));

    text2.setCharacterSize(size);
    text2.setPosition(left, top);

    window->draw(text2);
}

void g2_clear() {
    RectangleShape rectangle;

    rectangle.setFillColor(Color(0, 0, 0, 255));
    rectangle.setSize(sf::Vector2f(1200, 800));
    rectangle.setPosition(0, 0);

    window->draw(rectangle);
}