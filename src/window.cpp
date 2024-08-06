#include "../include/window.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
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
            event.type         = lame2D::EventType::MouseMove;
            event.mouse_move.x = e.motion.x;
            event.mouse_move.y = e.motion.y;
            break;
        };
        case SDL_KEYDOWN: {
            event.type = lame2D::EventType::KeyboardDown;
            switch (e.key.keysym.sym) {
            case (SDLK_a): {
                event.keyboard_down.k = lame2D::Key::A;
                break;
            };

            case (SDLK_d): {
                event.keyboard_down.k = lame2D::Key::D;
                break;
            };

            case (SDLK_s): {
                event.keyboard_down.k = lame2D::Key::S;
                break;
            };

            case (SDLK_w): {
                event.keyboard_down.k = lame2D::Key::W;
                break;
            };
            case (SDLK_q): {
                event.keyboard_down.k = lame2D::Key::Q;
                break;
            };
            case (SDLK_e): {
                event.keyboard_down.k = lame2D::Key::E;
                break;
            };
            case (SDLK_r): {
                event.keyboard_down.k = lame2D::Key::R;
                break;
            };
            case (SDLK_f): {
                event.keyboard_down.k = lame2D::Key::F;
                break;
            };
            case (SDLK_t): {
                event.keyboard_down.k = lame2D::Key::T;
                break;
            };
            case (SDLK_g): {
                event.keyboard_down.k = lame2D::Key::G;
                break;
            };
            case (SDLK_y): {
                event.keyboard_down.k = lame2D::Key::Y;
                break;
            };
            case (SDLK_h): {
                event.keyboard_down.k = lame2D::Key::H;
                break;
            };
            case (SDLK_u): {
                event.keyboard_down.k = lame2D::Key::U;
                break;
            };
            case (SDLK_j): {
                event.keyboard_down.k = lame2D::Key::J;
                break;
            };
            case (SDLK_i): {
                event.keyboard_down.k = lame2D::Key::I;
                break;
            };
            case (SDLK_k): {
                event.keyboard_down.k = lame2D::Key::K;
                break;
            };
            case (SDLK_o): {
                event.keyboard_down.k = lame2D::Key::O;
                break;
            };
            case (SDLK_l): {
                event.keyboard_down.k = lame2D::Key::L;
                break;
            };
            case (SDLK_p): {
                event.keyboard_down.k = lame2D::Key::P;
                break;
            };
            case (SDLK_SEMICOLON): {
                event.keyboard_down.k = lame2D::Key::SemiColon;
                break;
            };
            case (SDLK_LEFTBRACKET): {
                event.keyboard_down.k = lame2D::Key::LeftBracket;
                break;
            };
            case (SDLK_QUOTE): {
                event.keyboard_down.k = lame2D::Key::Quote;
                break;
            };
            case (SDLK_RIGHTBRACKET): {
                event.keyboard_down.k = lame2D::Key::RightBracket;
                break;
            };
            case (SDLK_BACKSLASH): {
                event.keyboard_down.k = lame2D::Key::BackSlash;
                break;
            };
            case (SDLK_z): {
                event.keyboard_down.k = lame2D::Key::Z;
                break;
            };
            case (SDLK_x): {
                event.keyboard_down.k = lame2D::Key::X;
                break;
            };
            case (SDLK_c): {
                event.keyboard_down.k = lame2D::Key::C;
                break;
            };
            case (SDLK_v): {
                event.keyboard_down.k = lame2D::Key::V;
                break;
            };
            case (SDLK_b): {
                event.keyboard_down.k = lame2D::Key::B;
                break;
            };
            case (SDLK_n): {
                event.keyboard_down.k = lame2D::Key::N;
                break;
            };
            case (SDLK_m): {
                event.keyboard_down.k = lame2D::Key::M;
                break;
            };
            case (SDLK_COMMA): {
                event.keyboard_down.k = lame2D::Key::Comma;
                break;
            };
            case (SDLK_PERIOD): {
                event.keyboard_down.k = lame2D::Key::Period;
                break;
            };
            case (SDLK_SLASH): {
                event.keyboard_down.k = lame2D::Key::Slash;
                break;
            };
            }
            break;
        };
        }
        return event;
    }
} // namespace lame2D
