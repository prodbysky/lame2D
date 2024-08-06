#include "../include/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <cstdint>
#include <iostream>
#include <optional>

namespace lame2D {
    Window::Window() {
        m_renderer = nullptr;
        m_window   = nullptr;
    }

    /**
     * You should noly really use this function if you want to setup SDL2
     * manually
     */
    Window::Window(SDL_Window* window, SDL_Renderer* renderer) {
        m_renderer = renderer;
        m_window   = window;
    }

    /**
     * Create a new Window based on SDL2's window and renderer
     * @param w Window width
     * @param h Window height
     * @param title Window title
     * @param vsync Use VSync?
     * @return std::optional with a value of window, or none if creating the
     * window has failed
     */
    std::optional<Window> Window::New(uint16_t w, uint16_t h, const char* title,
                                      bool vsync) {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            std::cerr << "Failed to initialize SDL: " << SDL_GetError() << '\n';
            return {};
        }

        SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED, w, h, 0);

        if (window == nullptr) {
            std::cerr << "Failed to create window: " << SDL_GetError() << '\n';
            return {};
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(
            window, -1,
            SDL_RENDERER_ACCELERATED | (SDL_RENDERER_PRESENTVSYNC * vsync));

        if (renderer == nullptr) {
            std::cerr << "Failed to create renderer: " << SDL_GetError()
                      << '\n';
            return {};
        }

        return std::make_optional<Window>(window, renderer);
    }
} // namespace lame2D
