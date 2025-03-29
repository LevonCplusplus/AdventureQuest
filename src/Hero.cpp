#include "Hero.h"
Hero::Hero(const std::string& name, int health, int attackPower, int defence)
    : Character(name, health, attackPower, defence), m_XP(0), m_level(0) {}

    std::string AbilitytoString(const Ability& ability)
    {
        if(ability == Ability::Abra_Cadabra){
           return " Abra_Cadabra ";
        }
        else if(ability == Ability::Shadow_Step){
            return " Shadow_Step ";
        }
        else if(ability == Ability::Silent_Strike){
            return" Silent_Strike ";
        }
        else if(ability == Ability::Berserker_Rage){
            return " Berserker_Rage ";
        }
        else if(ability == Ability::War_Cry){
            return " War_Cry ";
        }
        else if(ability == Ability::Fireball){
            return " Fireball ";
        }
        return "aper";
    }
void Hero::displayStats() const {
    Character::displayStats();
    std::cout << "XP:\t" << m_XP << "\nLevel:\t" << m_level << std::endl;
    std::cout << AbilitytoString(m_ability);
}

void Hero::takeDamage(int damage) {
    Character::takeDamage(damage);
}

// void Hero::Interact(Character* target) {
//     target -> getDialogue();
    
// }
void Hero:: levelup(){
    m_health += 10;
    m_attackPower += 10;
    m_item == Item::Kerambit;
}
std::string Hero::getDialogue() {
   std::string a = "1:I will help you!!";
   return a;
}

void Hero::attack(Character* target) {
    target->takeDamage(m_attackPower + static_cast<int>(m_item));
    if (!isalive()) {
        m_XP += m_level * 20;
    }
}

void Hero::useAbility(Character* target) {
    target->takeDamage(static_cast<int>(m_ability));
}

void Hero::setAbility(const Ability& ability) {
    m_ability = ability;
}

void Hero::setItem(const Item& item) {
    m_item = item;
}

Warrior::Warrior(const std::string& name) : Hero(name, 150,10 , 20) {
    setAbility(Ability::Berserker_Rage);
    setItem(Item::Ak_47);
}

Mage::Mage(const std::string& name) : Hero(name, 100, 10, 20) {
    setAbility(Ability::Fireball);
    setItem(Item::Magic_Wand);
}

Rogue::Rogue(const std::string& name) : Hero(name, 80, 10, 20) {
    setAbility(Ability::Shadow_Step);
    setItem(Item::Knife);
}
