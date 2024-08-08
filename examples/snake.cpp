#include "../include/window.hpp"

#include <cstdint>
#include <iostream>

constexpr int32_t WindowWidth  = 800;
constexpr int32_t WindowHeight = 800;
constexpr float TileSize       = 100;
constexpr int32_t TileCount    = WindowWidth / TileSize;

int run(lame2D::Window window);

int main() {
    auto window = lame2D::Window::New(WindowWidth, WindowHeight, "snake", true);

    if (!window.has_value()) {
        std::cerr << "Failed to create window exiting...\n";
        return 1;
    }

    return run(window.value());
}

int run(lame2D::Window window) {
    while (!window.ShouldClose()) {

        lame2D::Event event = window.PollEvent();

        while (event.type != lame2D::EventType::No) {
            event = window.PollEvent();
        }

        window.Clear(lame2D::Color(0x181818FF));
        window.Swap();
    }

    return 0;
}
