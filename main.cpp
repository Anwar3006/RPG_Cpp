#include "main.h"

int main()
{

    // Tests for Chapter_1
    // Warrior war1;
    // Wizard wiz1;
    // Cleric cler1;
    // Rogue rog1;
    // std::cout << "Warrior\n"
    //           << "\tMaxHP: " << war1.getMaxHp() << "\n"
    //           << "\tStrength: " << war1.getStrength() << "\n"
    //           << "\tIntellect: " << war1.getIntellect()
    //           << std::endl;

    // std::cout << "Wizard\n"
    //           << "\tMaxHP: " << wiz1.getMaxHp() << "\n"
    //           << "\tStrength: " << wiz1.getStrength() << "\n"
    //           << "\tIntellect: " << wiz1.getIntellect()
    //           << std::endl;

    // std::cout << "Cleric\n"
    //           << "\tMaxHP: " << cler1.getMaxHp() + 100u << "\n"
    //           << "\tStrength: " << cler1.getStrength() << "\n"
    //           << "\tIntellect: " << cler1.getIntellect()
    //           << std::endl;

    // std::cout << "Rogue\n"
    //           << "\tMaxHP: " << rog1.getMaxHp() << "\n"
    //           << "\tStrength: " << rog1.getStrength() << "\n"
    //           << "\tIntellect: " << rog1.getIntellect()
    //           << std::endl;

    // Tests for Chapter_2
    PlayerCharacter p1(new Warrior());

    for (int i = 0; i < 2; i++)
    {
        std::cout << p1.getClassName() << " Level: " << p1.getCurrentLevel() << "\n"
                  << "\tHP: " << p1.getCurrentHP() << " / " << p1.getMaxHP() << "\n"
                  << "\tEXP: " << p1.getCurrentEXP() << " / " << p1.getEXPToNextLevel() << "\n"
                  << "\tStrength: " << p1.getStrength() << "\n"
                  << "\tIntellect: " << p1.getIntellect() << "\n"
                  << std::endl;

        if (i < 1)
        {
            p1.gainEXP(105u);
        }
    }

    return 0;
}