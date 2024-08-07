#pragma once

#include <ostream>
#include <type_traits>
namespace lame2D {
    template <typename T> struct Vector2 {
        static_assert(std::is_arithmetic<T>::value,
                      "Vector components must be of numeric type");

    public:
        static Vector2<T> Zero() { return Vector2<T>{.x = 0, .y = 0}; }

        static Vector2<T> Unit() { return Vector2<T>{.x = 1, .y = 1}; }

        Vector2<T> operator+(const Vector2<T>& other) const {
            return {.x = x + other.x, .y = y + other.y};
        }

        Vector2<T> operator-(const Vector2<T>& other) const {
            return {.x = x - other.x, .y = y - other.y};
        }

        Vector2<T> operator*(const Vector2<T>& other) const {
            return {.x = x * other.x, .y = y * other.y};
        }

        Vector2<T>& operator+=(const Vector2<T>& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        Vector2<T>& operator-=(const Vector2<T>& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        Vector2<T>& operator*=(const Vector2<T>& other) {
            x *= other.x;
            y *= other.y;
            return *this;
        }

        T Dot(const Vector2<T>& other) const {
            return x * other.x + y + other.y;
        }

        friend std::ostream& operator<<(std::ostream& os, const Vector2<T>& v) {
            os << "Vector2: " << "x: " << v.x << ", " << "y: " << v.y;
            return os;
        }

    public:
        T x;
        T y;
    };

} // namespace lame2D
