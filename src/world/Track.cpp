#include "Track.h"
#include "../core/Config.h"

Coord Track::getSpawn() const
{
    return {Config::backGroundStartCoordX, Config::backGroundStartCoordY};
}

worldCollisionType Track::collisionDir(const Coord& pos) const
{
    if(pos.x < Config::MIN_X) return worldCollisionType::Left;
    if(pos.x > Config::MAX_X) return worldCollisionType::Right;
    if(pos.y < Config::MIN_Y) return worldCollisionType::Down;
    if(pos.y > Config::MAX_Y) return worldCollisionType::Up;
    
    return worldCollisionType::None;
}

float Track::frictionAt(const Coord&) const
{
    return Config::damping;
}

/*
    frictionAt : ileride çimen yavaşaması için eklendi
    inInside : world ün içinde mi
    getSpawn : ilk başlangıç yeri
*/