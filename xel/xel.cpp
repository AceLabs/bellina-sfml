#include <SFML/Graphics.hpp>

using namespace sf;

RenderWindow* xel_window;

void (*xel_g_afterGL_callback)() = 0;
void (*xel_g_beforeGLDeleted_callback)() = 0;
void (*xel_g_tick_callback)() = 0;
void (*xel_g_key_callback)(bool isKeyDown, sf::Keyboard::Key key) = 0;
void (*xel_g_mouse_move_callback)(int mouseX, int mouseY) = 0;
void (*xel_g_mouse_button_callback)(bool isButtonDown, int x, int y, Mouse::Button button) = 0;

void xel_init() {
    xel_window = new RenderWindow( VideoMode(1280, 800, 32), "Hello Bellina!" );
}

void xel_callback( void (*OnAfterGL)(),
                   void (*OnBeforeGLDeleted)(),
                   void (*OnTick)(),
                   void (*OnKey)(bool isKeyDown, sf::Keyboard::Key code),
                   void (*OnMouseMove)(int mouseX, int mouseY),
                   void (*OnMouseButton)(bool isButtonDown, int x, int y, Mouse::Button button)) {

    xel_g_afterGL_callback = OnAfterGL;
    xel_g_beforeGLDeleted_callback = OnBeforeGLDeleted;
    xel_g_tick_callback = OnTick;
    xel_g_key_callback = OnKey;
    xel_g_mouse_move_callback = OnMouseMove;
    xel_g_mouse_button_callback = OnMouseButton;
}

void xel_uninit() {
    delete xel_window;
}

void xel_loop() {

    if (xel_g_afterGL_callback)
        xel_g_afterGL_callback();

    while (xel_window->isOpen()) {

        Event event;

        while (xel_window->pollEvent(event)) {

            if (event.type == Event::MouseMoved) {
                if (xel_g_mouse_move_callback)
                    xel_g_mouse_move_callback( event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == Event::MouseButtonPressed || event.type == Event::MouseButtonReleased) {
                if (xel_g_mouse_button_callback)
                    xel_g_mouse_button_callback( event.type == Event::MouseButtonPressed, event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
            }
            else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                if (xel_g_key_callback) {
                    xel_g_key_callback(event.type == Event::KeyPressed, event.key.code);
                }
            }
            else if (event.type == sf::Event::Closed) {
                if (xel_g_beforeGLDeleted_callback)
                    xel_g_beforeGLDeleted_callback();

                xel_window->close();
            }
        }

        if (xel_g_tick_callback)
            xel_g_tick_callback();

        xel_window->display();
    }
}