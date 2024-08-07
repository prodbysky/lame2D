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
    auto rect =
        lame2D::Rectangle<int, int>({.x = 100, .y = 100}, {.x = 100, .y = 100});
    auto rect_color = lame2D::Color(0xff00ffff);
    auto bg_color   = lame2D::Color(0x181818ff);
    while (!window.ShouldClose()) {

        lame2D::Event event = window.PollEvent();

        while (event.type != lame2D::EventType::No) {

            event = window.PollEvent();
        }

        window.Clear(bg_color);
        window.DrawRectangle(rect, rect_color);
        window.Swap();
    }

    return 0;
}
