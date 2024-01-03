#pragma once
#include <cstdint>

typedef uint16_t pwType;

class PointWell
{
public:
    // setting the max Points
    bool setMaxPoints(pwType new_maxpoints)
    {
        if (new_maxpoints < 1)
        {
            return false;
        }
        MaxPoints = new_maxpoints;

        // check if the current Points is greater than the max Points
        if (CurrentPoints > MaxPoints)
        {
            CurrentPoints = MaxPoints;
        }

        return true;
    }

    // getters for CurrentPoints and MaxPoints
    pwType getCurrentPoints() { return CurrentPoints; }
    pwType getMaxPoints() { return MaxPoints; }

    // taking damage
    void takeDamage(pwType damage)
    {
        if (CurrentPoints < damage)
        {
            CurrentPoints = 0;
            return;
        }
        CurrentPoints -= damage;
    }

    // healing
    void heal(pwType amount)
    {
        if (amount + CurrentPoints > MaxPoints)
        {
            CurrentPoints = MaxPoints;
            return;
        }
        CurrentPoints += amount;
    }

    // constructor
    PointWell()
    {
        CurrentPoints = 1;
        MaxPoints = 1;
    }

    PointWell(pwType cp, pwType mp)
    {
        CurrentPoints = cp;
        MaxPoints = mp;

        if (CurrentPoints > MaxPoints)
        {
            CurrentPoints = MaxPoints;
        }
    }

private:
    pwType CurrentPoints;
    pwType MaxPoints;
};
