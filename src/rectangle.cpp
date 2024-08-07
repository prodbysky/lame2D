#include "../include/rectangle.hpp"

namespace lame2D {
    template <typename T, typename U>
    Rectangle<T, U>::Rectangle(lame2D::Vector2<T> pos,
                               lame2D::Vector2<U> size) :
        pos(pos), size(size) {}
} // namespace lame2D
