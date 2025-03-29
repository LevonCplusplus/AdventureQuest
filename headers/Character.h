#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include "Combatable.h"
#include "Interactable.h"

class Interactable;
class Combatable;

class Character {
protected:
    std::string m_name;
    int m_health;
    int m_attackPower;
    int m_defence;

public:
    Character() = default;
    Character(const std::string& name, int health, int attackPower, int defence);
    virtual ~Character() = default;
    virtual void showCharacter()const;
    virtual bool isalive() const;
    virtual void displayStats() const;
    virtual void takeDamage(int damage);
};

#endif  // CHARACTER_H
