#include "Monster.h"


Monster::Monster(const std::string &name, int health, int attackPower, int defence)
    : Character(name, health, attackPower, defence) {}

void Monster::displayStats() const {
    Character::displayStats();
    std::cout << "Ability: " << static_cast<int>(m_ability) << std::endl;
}

void Monster::takeDamage(int damage) {
    Character::takeDamage(damage);
}
std::string& Monster:: getName() {
    return m_name;
}
void Monster:: showCharacter()
{
    std::cout <<this->getName()<< "\tHealth:" << m_health <<"\tAttack: "<< m_attackPower << "\tDefense: "<< m_defence << std::endl;
}
void Monster::attack(Character *target) {
    target->takeDamage(m_attackPower);
}

void Monster::useAbility(Character *target) {
    target->takeDamage(static_cast<int>(m_ability));
}


Goblin::Goblin(const std::string &name) : Monster(name, 80, 10, 5) {
    m_ability = Monster_Ability::Explosive_Trap;
}

Troll::Troll(const std::string &name) : Monster(name, 150, 30, 30) {
    m_ability = Monster_Ability::Troll_Smash;
}

Dragon::Dragon(const std::string &name) : Monster(name, 100, 50, 30) {
    m_ability = Monster_Ability::Fire_Breath;
}
