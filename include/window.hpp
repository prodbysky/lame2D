#pragma once

#include "color.hpp"
#include "event.hpp"
#include "rectangle.hpp"

#include <SDL2/SDL.h>
#include <cstdint>
#include <optional>

namespace lame2D {
    class Window {

    public:
        Window();
        Window(SDL_Window* window, SDL_Renderer* renderer);
        ~Window();

    public:
        static std::optional<Window> New(uint16_t w, uint16_t h,
                                         const char* title, bool vsync);
        bool ShouldClose();

        template <typename T, typename U>
        void DrawRectangle(const lame2D::Rectangle<T, U>& rect,
                           const lame2D::Color& color);

        void Swap();
        void Clear(const lame2D::Color& color);

        lame2D::Event PollEvent();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_should_close = false;
    };
} // namespace lame2D
