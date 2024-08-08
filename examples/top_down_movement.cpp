#include "../include/window.hpp"

#include <iostream>
#include <ostream>

int run(lame2D::Window window);

int main() {
    auto window = lame2D::Window::New(1280, 720, "Top-Down movement", true);

    if (!window.has_value()) {
        std::cerr << "Failed to create window exiting...\n";
        return 1;
    }

    return run(window.value());
}

int run(lame2D::Window window) {
    lame2D::Rectangle<double, int> player({.x = 120, .y = 240},
                                          {.x = 64, .y = 64});
    lame2D::Vector2<double> velocity = lame2D::Vector2<double>::Zero();
    lame2D::Color color(0xaaaa00ff);

    while (!window.ShouldClose()) {
        lame2D::Event event = window.PollEvent();

        while (event.type != lame2D::EventType::No) {
            switch (event.type) {
            case lame2D::EventType::KeyboardAction: {
                switch (event.keyboard.k) {
                case lame2D::Key::W: {
                    velocity.y = -1 * event.keyboard.down;
                    break;
                };
                case lame2D::Key::A: {
                    velocity.x = -1 * event.keyboard.down;
                    break;
                };
                case lame2D::Key::S: {
                    velocity.y = 1 * event.keyboard.down;
                    break;
                };
                case lame2D::Key::D: {
                    velocity.x = 1 * event.keyboard.down;
                    break;
                };
                default:
                    break;
                }
                break;
            }
            default:
                break;
            };
            event = window.PollEvent();
        }

        const lame2D::Vector2<double> mul  = {.x = 0.03, .y = 0.03};
        player.pos                        += velocity * mul;

        window.Clear(lame2D::Color(0x181818ff));
        window.DrawRectangle(player, color);
        window.Swap();
    }
    return 0;
}
