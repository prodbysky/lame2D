#pragma once

#include <SDL2/SDL.h>
#include <cstdint>
#include <optional>

/**
 * lame2D Window
 */
namespace lame2D {
    class Window {

    public:
        Window();
        Window(SDL_Window* window, SDL_Renderer* renderer);
        constexpr Window(const Window& w) = delete;

    public:
        static std::optional<Window> New(uint16_t w, uint16_t h,
                                         const char* title, bool vsync);

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
    };
} // namespace lame2D
