#include "../include/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <cstdint>
#include <iostream>
#include <optional>

namespace lame2D {
    Window::Window() {
        m_renderer = nullptr;
        m_window   = nullptr;
    }

    Window::Window(SDL_Window* window, SDL_Renderer* renderer) {
        m_renderer = renderer;
        m_window   = window;
    }

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

    bool Window::ShouldClose() { return m_should_close; }

    lame2D::Event Window::PollEvent() {
        SDL_Event e;
        lame2D::Event event;
        event.type = lame2D::EventType::Zero;
        if (SDL_PollEvent(&e) == 0) {
            event.type = lame2D::EventType::No;
            return event;
        }

        switch (e.type) {
        case SDL_QUIT: {
            m_should_close = true;
            break;
        };
        case SDL_MOUSEMOTION: {
            event.type            = lame2D::EventType::MouseMove;
            event.mouse_move.type = lame2D::EventType::MouseMove;
            event.mouse_move.x    = e.motion.x;
            event.mouse_move.y    = e.motion.y;
        };
        }
        return event;
    }
} // namespace lame2D
