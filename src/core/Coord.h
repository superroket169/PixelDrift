#pragma once
/**
 * @brief Coord is struct that is will use for entity's coordinates
 * * That strucure stores coordinate of entitys 2D x and y
 */
struct Coord
{
    float x = 0.f; /**< Horizontal coordinate */
    float y = 0.f; /**< Vertical coordinate */

    /**
     * @brief default constructor 
     */
    constexpr Coord() = default;
    
    /**
     * @brief constructor that able to assign inital value
     */
    constexpr Coord(float x_, float y_) : x(x_), y(y_) {}

    /**
     * @brief addition opeartor
    */
    constexpr Coord operator+(const Coord& other) const { return { x + other.x, y + other.y };}

    /**
     * @brief subtraction opeartor
    */
    constexpr Coord operator-(const Coord& other) const { return { x - other.x, y - other.y };}

    /**
     * @brief addition assignment opeartor
    */
    constexpr Coord& operator+=(const Coord& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    /**
     * @brief subtraction assignment operator
    */
    constexpr Coord& operator-=(const Coord& other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }
};
