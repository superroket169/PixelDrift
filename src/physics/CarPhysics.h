#pragma once

/*
    what will happen here:
        Optimum gear calculate for autoGear
        steerign code for steering 
        acceleration code with sigmoids

    planed : bool  rearSlip;
    planed : float slipAmount;
        
*/

namespace Physics
{

    enum class Gear
    {
        R = 0,
        One = 1,
        Two = 2,
        Three = 3,
        Four = 4,
        Five = 5,
        Six = 6,
        Seven = 7
    };

    enum class steerStatus
    {
        Left = -1,
        Right = 1,
        Forward = 0
    };

    struct Input
    {
        float velocityX;
        float velocityY;
        float steeredTime;
        float carAngle;
        steerStatus steerDir;
        bool throttle;     // aralık :  0 -> 1
        bool  handbrake;
        bool  brake;
        Gear  gear;
        bool  autoGear;
    };

    struct Output
    {
        float acceleration;
        float angularVelocity;
        float dirMultiplerX;
        float dirMultiplerY;
        bool  slip;
        // planed : bool  rearSlip;
        // planed : float slipAmount;
        Gear  recommendedGear;
    };

    struct vectorVelocity
    {
        float DirX;
        float DirY;
    };

    class CarPhysics
    {
    public:
        Output update(const Input& input, float dt);

    private:
        static float dampingMultiplier;
        
        Gear calculateOptGear(float speed) const;
        float computeAcceleration(const Input& input, float speed) const;
        float computeSteer(float speed, float steeredTime, steerStatus steerDir) const;
        float computeSpeed(float velocityX, float velocityY) const;
        vectorVelocity computeDirVelocity(float accel, float carAngle) const;
    };
}

// brake kodu eklenecek
