#include "../include/window.hpp"

#include <iostream>

int main() {
    auto window = lame2D::Window::New(1280, 720, "Hello!", true);

    if (!window.has_value()) {
        std::cerr << "Failed to create window exiting...\n";
        return 1;
    }
}
