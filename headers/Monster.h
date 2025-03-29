#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"


class Character;
enum class Monster_Ability { Fire_Breath = 35, Explosive_Trap = 20, Troll_Smash = 30 };

class Monster : public Character, public Combatable {
protected:
    Monster_Ability m_ability;

public:
    Monster(const std::string &, int, int, int);
    void displayStats() const override;
    void takeDamage(int damage) override;
    std::string& getName() ;
    void showCharacter();
    void attack(Character *target) override;
    void useAbility(Character *target) override;
};

class Goblin : public Monster {
public:
    Goblin(const std::string &name);
};

class Troll : public Monster {
public:
    Troll(const std::string &name);
};

class Dragon : public Monster {
public:
    Dragon(const std::string &name);
};

#endif
