#pragma once

#include "event.hpp"

#include <SDL2/SDL.h>
#include <cstdint>
#include <optional>

namespace lame2D {
    class Window {

    public:
        Window();
        Window(SDL_Window* window, SDL_Renderer* renderer);

    public:
        static std::optional<Window> New(uint16_t w, uint16_t h,
                                         const char* title, bool vsync);
        bool ShouldClose();

        lame2D::Event PollEvent();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_should_close = false;
    };
} // namespace lame2D
