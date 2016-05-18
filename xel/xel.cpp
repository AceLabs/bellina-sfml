#include <SFML/Graphics.hpp>

using namespace sf;

namespace xel {

    RenderWindow *window;

    void (*g_afterGL_callback)() = 0;

    void (*g_beforeGLDeleted_callback)() = 0;

    void (*g_tick_callback)() = 0;

    void (*g_key_callback)(bool isKeyDown, sf::Keyboard::Key key) = 0;

    void (*g_mouse_move_callback)(int mouseX, int mouseY) = 0;

    void (*g_mouse_button_callback)(bool isButtonDown, int x, int y, Mouse::Button button) = 0;
}

using namespace xel;

void xel_init() {
    window = new RenderWindow( VideoMode(1280, 800, 32), "Hello Bellina!" );
}

void xel_callback( void (*OnAfterGL)(),
                   void (*OnBeforeGLDeleted)(),
                   void (*OnTick)(),
                   void (*OnKey)(bool isKeyDown, sf::Keyboard::Key code),
                   void (*OnMouseMove)(int mouseX, int mouseY),
                   void (*OnMouseButton)(bool isButtonDown, int x, int y, Mouse::Button button)) {

    g_afterGL_callback = OnAfterGL;
    g_beforeGLDeleted_callback = OnBeforeGLDeleted;
    g_tick_callback = OnTick;
    g_key_callback = OnKey;
    g_mouse_move_callback = OnMouseMove;
    g_mouse_button_callback = OnMouseButton;
}

void xel_uninit() {
    delete window;
}

void xel_loop() {

    if (g_afterGL_callback)
        g_afterGL_callback();

    while (window->isOpen()) {

        Event event;

        while (window->pollEvent(event)) {

            if (event.type == Event::MouseMoved) {
                if (g_mouse_move_callback)
                    g_mouse_move_callback( event.mouseMove.x, event.mouseMove.y);
            }
            else if (event.type == Event::MouseButtonPressed || event.type == Event::MouseButtonReleased) {
                if (g_mouse_button_callback)
                    g_mouse_button_callback( event.type == Event::MouseButtonPressed, event.mouseButton.x, event.mouseButton.y, event.mouseButton.button);
            }
            else if (event.type == Event::KeyPressed || event.type == Event::KeyReleased) {
                if (g_key_callback) {
                    g_key_callback(event.type == Event::KeyPressed, event.key.code);
                }
            }
            else if (event.type == sf::Event::Closed) {
                if (g_beforeGLDeleted_callback)
                    g_beforeGLDeleted_callback();

                window->close();
            }
        }

        if (g_tick_callback)
            g_tick_callback();

        window->display();
    }
}