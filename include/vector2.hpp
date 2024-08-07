#pragma once

#include <ostream>
namespace lame2D {
    template <typename T> struct Vector2 {
    public:
        static Vector2<T> Zero();
        static Vector2<T> Unit();

        Vector2<T> operator+(const Vector2<T>& other);
        Vector2<T> operator-(const Vector2<T>& other);
        Vector2<T> operator*(const Vector2<T>& other);

        Vector2<T>& operator+=(const Vector2<T>& other);
        Vector2<T>& operator-=(const Vector2<T>& other);
        Vector2<T>& operator*=(const Vector2<T>& other);

        template <class U>
        friend std::ostream& operator<<(std::ostream& os, const Vector2<U>& v);

        T Dot(const Vector2<T>& other);

    public:
        T x;
        T y;
    };

} // namespace lame2D
