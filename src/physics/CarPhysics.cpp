// CarPhysics.cpp:
#include "CarPhysics.h"
#include "../core/Utils.h"
#include "../core/Config.h"

Physics::Output Physics::CarPhysics::update(const Input& input, float dt)
{
    Physics::Output out;

    out.acceleration = computeAcceleration(input.speed, input.gear, input.throttle);
    out.angularVelocity = computeSteer(input.speed, input.steeredTime ,input.steerDir);
    out.slip = input.handbrake;

    if(input.autoGear)
        out.recommendedGear = calculateOptGear(input.speed);
    else
        out.recommendedGear = input.gear;

    return out;
}

Physics::Gear Physics::CarPhysics::calculateOptGear(float speed) const
{
    
    for(size_t i = 1; i <= 7; ++i)
        if(speed < Config::gearMaxes[i] * Config::recommenedGearConstant) return static_cast<Physics::Gear>(i);

    return Physics::Gear::Seven;
}

float Physics::CarPhysics::computeAcceleration(float speed, Physics::Gear gear, bool throttle) const
{
    if(throttle)
    {
        if(gear == Physics::Gear::R) return Config::gearAccels[0];
        int intGear = static_cast<int>(gear);
        return sigmoid(speed, Config::gearMaxes[intGear] / 3, Config::gearMaxes[1] * Config::gearMaxes[1] / Config::gearMaxes[intGear], Config::gearAccels[intGear], Config::SigmoidKConstant);

        // plan : sigmoid will be simplefied
    }
    return 0;
}

float Physics::CarPhysics::computeSteer(float speed, float steeredTime, steerStatus steerDir) const
{
    if(steerDir == Physics::steerStatus::Left) return -Config::turnSpeed * pow(speed, Config::turnPowConstant) * steeredTime;
    if(steerDir == Physics::steerStatus::Right) return Config::turnSpeed * pow(speed, Config::turnPowConstant) * steeredTime;
    return 0.f;
}
