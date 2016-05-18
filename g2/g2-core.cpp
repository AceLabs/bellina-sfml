#include <SFML/Graphics.hpp>

using namespace sf;

namespace xel { extern RenderWindow* window; };

RenderWindow* g;

unsigned int G2_COLOR = 1 << 0;
unsigned int G2_ALPHA = 1 << 1;

Font g2v_font;
int g2v_red, g2v_green, g2v_blue, g2v_alpha;

void g2_init() {
    g = xel::window;

    g2v_font.loadFromFile("fonts/OpenSans/OpenSans-Bold.ttf");
}

void g2_uninit() {
}

void g2_color(int red, int green, int blue) {
    g2v_red = red;
    g2v_green = green;
    g2v_blue = blue;
}

void g2_alpha(int alpha) {
    g2v_alpha = alpha;
}

void g2_rect(unsigned int flags, int left, int top, int width, int height) {
    RectangleShape rectangle;

    if (flags & G2_COLOR)
        rectangle.setFillColor(Color(g2v_red, g2v_green, g2v_blue, 255));

    if (flags & G2_ALPHA)
        rectangle.setFillColor(Color(g2v_red, g2v_green, g2v_blue, g2v_alpha));

    rectangle.setSize(sf::Vector2f(width, height));
    rectangle.setOutlineColor(Color::Red);
    rectangle.setOutlineThickness(1);
    rectangle.setPosition(left, top);
    g->draw(rectangle);
}

void g2_text(int left, int top, char* text, int size) {
    sf::Text text2(text, g2v_font, 11);
    text2.setCharacterSize(size);
    text2.setPosition(left, top);

    g->draw(text2);
}

void g2_clear() {
    RectangleShape rectangle;

    rectangle.setFillColor(Color(0, 0, 0, 255));
    rectangle.setSize(sf::Vector2f(1200, 800));
    rectangle.setPosition(0, 0);

    g->draw(rectangle);
}