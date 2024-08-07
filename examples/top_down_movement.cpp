#include "../include/window.hpp"

#include <iostream>

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
    lame2D::Rectangle<int, int> player({.x = 120, .y = 240},
                                       {.x = 64, .y = 64});
    lame2D::Color color(0xaaaa00ff);

    while (!window.ShouldClose()) {
        lame2D::Event event = window.PollEvent();

        while (event.type != lame2D::EventType::No) {
            switch (event.type) {
            case lame2D::EventType::KeyboardDown: {
                switch (event.keyboard_down.k) {
                case lame2D::Key::W: {
                    player.pos.y -= 10;
                    break;
                };
                case lame2D::Key::A: {
                    player.pos.x -= 10;
                    break;
                };
                case lame2D::Key::S: {
                    player.pos.y += 10;
                    break;
                };
                case lame2D::Key::D: {
                    player.pos.x += 10;
                    break;
                };
                default:
                    break;
                }
                break;
            };
            default:
                break;
            }
            event = window.PollEvent();
        }

        window.Clear(lame2D::Color(0x181818ff));
        window.DrawRectangle(player, color);
        window.Swap();
    }
    return 0;
}
