#include "../include/vector2.hpp"

#include <ostream>

namespace lame2D {

    template <typename T> Vector2<T> Vector2<T>::Zero() {
        return Vector2<T>{.x = 0, .y = 0};
    }

    template <typename T> Vector2<T> Vector2<T>::Unit() {
        return Vector2<T>{.x = 1, .y = 1};
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator+(const Vector2<T>& other) {
        return {.x = x + other.x, .y = y + other.y};
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator-(const Vector2<T>& other) {
        return {.x = x - other.x, .y = y - other.y};
    }

    template <typename T>
    Vector2<T> Vector2<T>::operator*(const Vector2<T>& other) {
        return {.x = x * other.x, .y = y * other.y};
    }

    template <typename T>
    Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    template <typename T>
    Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    template <typename T>
    Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }

    template <typename T> T Vector2<T>::Dot(const Vector2<T>& other) {
        return x * other.x + y + other.y;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
        os << "x: " << v.x << ", " << "y: " << v.y;
        return os;
    }

    // TODO: Find a diffrent way of restricting types
    template class Vector2<int>;
    template class Vector2<float>;
    template class Vector2<double>;
} // namespace lame2D
