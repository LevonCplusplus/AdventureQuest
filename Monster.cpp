#include "Monster.h" 

class Monster:public Character,public Combatable{
    // std::string m_name;
    // int m_health;
    // int m_attackPower;
    // int m_defence;
    // protected:
    Ability m_ability;
    
public:
    Monster(const std::string&);
    //virtual void displayStats()const = 0; 
    //virtual void takeDamage(int damage) = 0;
    //virtual void attack(Character* target) = 0; 
    //virtual void useAbility(Character* target) = 0;
    //karelia//// virtual void Interact(Character* target) = 0;
    //karelia//// virtual void getDialogue() = 0;
};
Monster::Monster(const std::string & name,int health,int attackPower,int defence):Character(name,health,attackPower,defence){}
void Monster::displayStats()const
{
    Character::displayStats();
    std::cout << MonsterAbilitytoString(m_ability);
}
void Monster::takeDamage(int damage){
    Character::takeDamage(damage);
}
void Monster::attack(Character * target){
    target -> takeDamage(m_attackPower);
}
void Monster::useAbility(Character *target){
    target -> takeDamage(static_cast<int>(m_ability)); 
}

Goblin::Goblin(const std::string & name):Monster(name,80,10,5){
    m_ability = Monster_Ability::Explosive_Trap;  
}

Troll::Troll(const std::string& name):Monster(name,150,30,30){
    m_ability = Monster_Ability::Troll_Smash;
}

Dragon::Dragon(const std::string& name):Monster(name,100,50,30){
    m_ability = Monster_Ability::Fire_Breath;
}