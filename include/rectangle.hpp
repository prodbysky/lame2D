#pragma once

#include "vector2.hpp"
namespace lame2D {
    template <typename T, typename U> struct Rectangle {
    public:
        Rectangle<T, U>(lame2D::Vector2<T> pos, lame2D::Vector2<U> size);

    public:
        lame2D::Vector2<T> pos;
        lame2D::Vector2<U> size;
    };
} // namespace lame2D
