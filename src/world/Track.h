#pragma once

#include "core/Coord.h"

enum class worldCollisionType
{
    Up,
    Down,
    Left,
    Right,
    None = 0
};

class Track
{
public:
    Coord getSpawn() const;
    worldCollisionType collisionDir(const Coord& pos) const;
    float frictionAt(const Coord&) const;
};
