#pragma once

enum class Action
{
    Throttle,
    Brake,
    HandBrake,
    Pause,
    SteerRight,
    SteerLeft,
    GearAuto,
    GearUp,
    GearDown
};

/**
 * @todo Implement costumsizeble input mapping:
 * - Add InputManager Class
 * - save/load key mappings by json
 * - Add default setting
 * - Add a menu to setting for user 
 */
class KeyInput 
{
public:
    static void update();
    static bool isDown(Action action);
    static bool isPressed(Action action);
};
