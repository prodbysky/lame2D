#pragma once

#include <cstdint>
namespace lame2D {
    struct Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;

    public:
        Color(uint32_t c);
        Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);
    };

} // namespace lame2D
