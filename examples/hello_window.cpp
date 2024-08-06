#include "../include/window.hpp"

#include <iostream>

int run(lame2D::Window window);

int main() {
    auto window = lame2D::Window::New(1280, 720, "Hello!", true);

    if (!window.has_value()) {
        std::cerr << "Failed to create window exiting...\n";
        return 1;
    }

    return run(window.value());
}

int run(lame2D::Window window) {
    while (!window.ShouldClose()) {
        lame2D::Event event = window.PollEvent();

        switch (event.type) {
        case lame2D::EventType::MouseMove: {
            std::cerr << event.mouse_move.x << '\n';
            std::cerr << event.mouse_move.y << '\n';
            break;
        };
        case lame2D::EventType::KeyboardDown: {
            std::cerr << lame2D::to_underlying(event.keyboard_down.k) << '\n';
            break;
        };

        default:
            break;
        }
    }

    return 0;
}
