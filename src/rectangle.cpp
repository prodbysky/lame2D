#include "../include/rectangle.hpp"

namespace lame2D {
    template <typename T, typename U>
    Rectangle<T, U>::Rectangle(lame2D::Vector2<T> pos,
                               lame2D::Vector2<U> size) :
        pos(pos), size(size) {}

    // TODO: Find a diffrent way of restricting types
    template class Rectangle<int, int>;
    template class Rectangle<int, float>;
    template class Rectangle<int, double>;

    template class Rectangle<float, int>;
    template class Rectangle<float, float>;
    template class Rectangle<float, double>;

    template class Rectangle<double, int>;
    template class Rectangle<double, float>;
    template class Rectangle<double, double>;

} // namespace lame2D
