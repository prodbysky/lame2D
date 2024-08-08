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
                           const lame2D::Color& color) {
            SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b,
                                   color.a);

            auto sdL_rect = SDL_Rect{.x = static_cast<int>(rect.pos.x),
                                     .y = static_cast<int>(rect.pos.y),
                                     .w = static_cast<int>(rect.size.x),
                                     .h = static_cast<int>(rect.size.y)};
            SDL_RenderFillRect(m_renderer, &sdL_rect);
        }

        void Swap();
        void Clear(const lame2D::Color& color);

        lame2D::Event PollEvent();

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_should_close = false;
    };
} // namespace lame2D
