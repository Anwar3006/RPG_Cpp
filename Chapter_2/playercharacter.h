#pragma once

#include <iostream>
#include <cstdint>
#include <memory.h>
#include <string>

#include "../Chapter_1/pointwell.h"
#include "../Chapter_1/statblock.h"

using namespace std;

typedef uint64_t expType;
typedef uint16_t levelType;

// Class for all player character types and their battle stats
class PlayerCharacterDelegate : public Statblock
{
public:
    static const expType LEVEL2STARTS = 100u;
    // constructor
    PlayerCharacterDelegate() : Statblock(0u, 0u)
    {
        Currentlevel = 1u;
        CurrentEXP = 0u;
        EXPToNextLevel = LEVEL2STARTS;
        HP = std::make_unique<PointWell>();
    }

    void gainEXP(expType exp)
    {
        CurrentEXP += exp;
        while (check_if_leveledUp())
        {
        };
    }

    // getters
    levelType getCurrentLevel() { return Currentlevel; }
    expType getCurrentEXP() { return CurrentEXP; };
    expType getEXPToNextLevel() { return EXPToNextLevel; };

    // Virtual Functions need to be implemented in the derived classes
    virtual void LevelUp() = 0;
    virtual string getClassName() = 0;
    virtual ~PlayerCharacterDelegate() = 0; // Pure virtual destructor

    // instead of instantiating PointWell each time we want to use it, we use a pointer to point to it memory location and use the pointer instead
    std::unique_ptr<PointWell> HP;

protected:
    levelType Currentlevel;
    expType CurrentEXP;
    expType EXPToNextLevel;

    bool check_if_leveledUp()
    {
        static const levelType LEVELUPMULTIPLIER = 2u;
        if (CurrentEXP >= EXPToNextLevel)
        {
            Currentlevel++;
            LevelUp();
            EXPToNextLevel *= LEVELUPMULTIPLIER;
            return true;
        }

        return false;
    };
};

//////////////////////////////////// Cleric Player Character
class Cleric : public PlayerCharacterDelegate
{
public:
    static const pwType BASEHP = 14u;
    static const statType BASESTRENGTH = 2u;
    static const statType BASEINTELLECT = 3u;

    Cleric() : PlayerCharacterDelegate()
    {
        HP->setMaxPoints(BASEHP);
        HP->heal(BASEHP);
        increaseStats(BASESTRENGTH, BASEINTELLECT);
    };

    string getClassName() { return "Cleric"; };

private:
    void LevelUp()
    {
        HP->setMaxPoints((pwType)((BASEHP / 2) + HP->getMaxPoints()));
        HP->heal((pwType)(BASEHP / 2));
        increaseStats((statType)((BASESTRENGTH + 1u) / 2.f), (statType)((BASEINTELLECT + 1u) / 2.f));
    };
};

//////////////////////////////////// Warrior Player Character
class Warrior : public PlayerCharacterDelegate
{
public:
    static const pwType BASEHP = 18u;
    static const statType BASESTRENGTH = 4u;
    static const statType BASEINTELLECT = 1u;

    Warrior() : PlayerCharacterDelegate()
    {
        HP->setMaxPoints(BASEHP);
        HP->heal(BASEHP);
        increaseStats(BASESTRENGTH, BASEINTELLECT);
    };

    string getClassName() { return "Warrior"; };

private:
    void LevelUp()
    {
        HP->setMaxPoints((pwType)((BASEHP / 2) + HP->getMaxPoints()));
        HP->heal((pwType)(BASEHP / 2));
        increaseStats((pwType)((BASESTRENGTH + 1u) / 2), (pwType)((BASEINTELLECT + 1u) / 2));
    };
};

//////////////////////////////////// Rogue Player Character
class Rogue : public PlayerCharacterDelegate
{
public:
    static const pwType BASEHP = 12u;
    static const statType BASESTRENGTH = 3u;
    static const statType BASEINTELLECT = 2u;

    Rogue() : PlayerCharacterDelegate()
    {
        HP->setMaxPoints(BASEHP);
        HP->heal(BASEHP);
        increaseStats(BASESTRENGTH, BASEINTELLECT);
    };

    string getClassName() { return "Rogue"; };

private:
    void LevelUp()
    {
        HP->setMaxPoints((pwType)((BASEHP / 2) + HP->getMaxPoints()));
        HP->heal((pwType)(BASEHP / 2));
        increaseStats((pwType)((BASESTRENGTH + 1u) / 2), (pwType)((BASEINTELLECT + 1u) / 2));
    };
};

//////////////////////////////////// Wizard Player Character
class Wizard : public PlayerCharacterDelegate
{
public:
    static const pwType BASEHP = 10u;
    static const statType BASESTRENGTH = 1u;
    static const statType BASEINTELLECT = 4u;

    Wizard() : PlayerCharacterDelegate()
    {
        HP->setMaxPoints(BASEHP);
        HP->heal(BASEHP);
        increaseStats(BASESTRENGTH, BASEINTELLECT);
    };

    string getClassName() { return "Wizard"; };

private:
    void LevelUp()
    {
        HP->setMaxPoints((pwType)((BASEHP / 2) + HP->getMaxPoints()));
        HP->heal((pwType)(BASEHP / 2));
        increaseStats((pwType)((BASESTRENGTH + 1u) / 2), (pwType)((BASEINTELLECT + 1u) / 2));
    };
};

PlayerCharacterDelegate::~PlayerCharacterDelegate() = default;
//////////////////////////////////// Player Character
class PlayerCharacter
{
public:
    // deleted constructor declaration: attempting to create an instance of PlayerCharacter using the default constructor is not allowed
    PlayerCharacter() = delete;

    // constructor
    PlayerCharacter(PlayerCharacterDelegate *pc) : pcClass(pc) {}

    // destructor
    virtual ~PlayerCharacter()
    {
        delete pcClass;
        pcClass = nullptr;
    };

    // functions to expose to player character constrcutor
    string getClassName() { return pcClass->getClassName(); };
    levelType getCurrentLevel() { return pcClass->getCurrentLevel(); };
    expType getCurrentEXP() { return pcClass->getCurrentEXP(); };
    expType getEXPToNextLevel() { return pcClass->getEXPToNextLevel(); };
    pwType getCurrentHP() { return pcClass->HP->getCurrentPoints(); };
    pwType getMaxHP() { return pcClass->HP->getMaxPoints(); };
    statType getStrength() { return pcClass->getStrength(); };
    statType getIntellect() { return pcClass->getIntellect(); };

    void gainEXP(expType amount) { return pcClass->gainEXP(amount); };
    void takeDamage(pwType amount) { return pcClass->HP->takeDamage(amount); };
    void heal(pwType amount) { return pcClass->HP->heal(amount); };

private:
    PlayerCharacterDelegate *pcClass;
};