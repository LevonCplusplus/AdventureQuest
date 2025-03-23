#ifndef MONSTER_H
#define MONSTER_H
#include "Character.h"
enum class Monster_Ability{Fire_Breath = 35,Explosive_Trap = 20,Troll_Smash = 30}
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

class Goblin {
    Goblin(const std::string & name);
   
}; 
    
class Troll { 
    //(high health, slow)
    Troll(const std::string& name);
};

class Dragon {
    Dragon(const std::string& name);
    //(strong, with special abilities like fire breath)

};


#endif