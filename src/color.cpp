#include "../include/color.hpp"

#include <cstdint>

namespace lame2D {
    Color::Color(uint32_t c) {
        a = c & 0xFF;
        b = (c >> 8) & 0xFF;
        g = (c >> 16) & 0xFF;
        r = (c >> 24) & 0xFF;
    }
    Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
        r = red;
        g = green;
        b = blue;
        a = alpha;
    }
} // namespace lame2D
