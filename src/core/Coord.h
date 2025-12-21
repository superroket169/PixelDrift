#pragma once

struct Coord
{
    float x = 0.f;
    float y = 0.f;

    constexpr Coord() = default;
    constexpr Coord(float x_, float y_) : x(x_), y(y_) {}

    constexpr Coord operator+(const Coord& other) const
    {
        return { x + other.x, y + other.y };
    }

    constexpr Coord operator-(const Coord& other) const
    {
        return { x - other.x, y - other.y };
    }

    constexpr Coord& operator+=(const Coord& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    constexpr Coord& operator-=(const Coord& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};
