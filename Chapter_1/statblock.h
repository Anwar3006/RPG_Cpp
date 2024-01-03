#pragma once
#include <cstdint>

typedef uint16_t statType;
// can't use unit_8 because it is too small and the output would be represented in hexadecimal: 0x04 = uint8_t 4u

class Statblock
{
    statType Strength; // 4 bytes because we are using uint8 for the statType
    statType Intellect;

public:
    // constructor
    Statblock()
    {
        Strength = 1u;
        Intellect = 1u;
    }

    explicit Statblock(statType strength, statType intellect)
    {
        Strength = strength;
        Intellect = intellect;
    }

    // getters
    statType getStrength() { return Strength; }
    statType getIntellect() { return Intellect; }

protected:
    void increaseStats(statType strength, statType intellect)
    {
        Strength += strength;
        Intellect += intellect;
    };
};
