// CarPhysics.cpp:
#include <cmath>
#include "CarPhysics.h"
#include "../core/Utils.h"
#include "../core/Config.h"

Physics::Output Physics::CarPhysics::update(const Input& input, float dt)
{
    Physics::Output out;

    float speed = computeSpeed(input.velocityX, input.velocityY);

    out.acceleration = computeAcceleration(input, speed);
    Physics::vectorVelocity tmp = computeDirVelocity(out.acceleration, input.carAngle);
    out.dirMultiplerX = tmp.DirX; out.dirMultiplerY = tmp.DirY; 
    out.angularVelocity = computeSteer(speed, input.steeredTime ,input.steerDir);
    out.recommendedGear = calculateOptGear(speed);
    out.slip = input.handbrake;


    return out;
}

Physics::Gear Physics::CarPhysics::calculateOptGear(float speed) const
{
    
    for(size_t i = 1; i <= 7; ++i)
        if(speed < Config::gearMaxes[i] * Config::recommenedGearConstant) return static_cast<Physics::Gear>(i);

    return Physics::Gear::Seven;
}

float Physics::CarPhysics::computeAcceleration(const Physics::Input& input, float speed) const
{
    float functAccel = 0;

    if(input.throttle)
    {
        if(input.gear == Physics::Gear::R) return Config::gearAccels[0];
        int intGear = static_cast<int>(input.gear);
        functAccel = sigmoid(speed, Config::gearMaxes[intGear] / 3, Config::gearMaxes[1] * Config::gearMaxes[1] / Config::gearMaxes[intGear], Config::gearAccels[intGear], Config::SigmoidKConstant);

        // plan : sigmoid will be simplefied
    }
    
    float velAngleDeg = std::fmod(std::atan2(input.velocityY, input.velocityX) * Config::RAD2DEG + 360, 360);
    float carAngle = std::fmod(carAngle + 360, 360);
    float rel = velAngleDeg - carAngle;
    
    if (rel > 180) rel -= 360;
    if (rel < -180) rel += 360;
    
    rel = std::abs(rel);
    if (rel > 90) rel = 90;

    if(input.handbrake) dampingMultiplier = 1 + Config::handBrakeForce;
    else dampingMultiplier = 1 + Config::MaxExtraTurnSpeed * (rel / 90);//re/90 en fazla 1 // burası en fazla 1 + 4 den 5 oluyo
}

float Physics::CarPhysics::computeSteer(float speed, float steeredTime, steerStatus steerDir) const
{
    if(steerDir == Physics::steerStatus::Left) return -Config::turnSpeed * pow(speed, Config::turnPowConstant) * steeredTime;
    if(steerDir == Physics::steerStatus::Right) return Config::turnSpeed * pow(speed, Config::turnPowConstant) * steeredTime;
    return 0.f;
}

float Physics::CarPhysics::computeSpeed(float velocityX, float velocityY) const
{
    return std::sqrt(velocityX * velocityX + velocityY * velocityY);
}


Physics::vectorVelocity Physics::CarPhysics::computeDirVelocity(float accel, float carAngle) const
{
    return {std::cos(carAngle), std::sin(carAngle)};
}