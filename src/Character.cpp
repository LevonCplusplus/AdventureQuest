#include "Character.h"
#include <iostream>
#include <algorithm>  // For std::max

Character::Character(const std::string& name, int health, int attackPower, int defence)
    : m_name(name), m_health(health), m_attackPower(attackPower), m_defence(defence) {}

void Character::displayStats() const {
    std::cout << "Name:\t" << m_name
              << "\nHealth:\t" << m_health
              << "\nAttack Power:\t" << m_attackPower
              << "\nDefence:\t" << m_defence << std::endl;
}

bool Character::isalive() const {
    return m_health > 0;
}
void Character:: showCharacter()const
{
    std::cout << "Health:" << m_health << "\tAttack: "<< m_attackPower << "\tDefense: "<< m_defence << std::endl;
}
void Character::takeDamage(int damage) {
    m_health -= damage < m_defence ? 0 : (damage - m_defence);
}
