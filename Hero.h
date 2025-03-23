#ifndef HERO_H
#define HERO_H
#include "Character.h"
#include <vector>
enum class Item {Knife = 15, Kerambit = 30, Magic_Wand = 20, Dragon_Sword = 40, Ak_47 = 30, Igla = 60}
enum class Ability{Abra_Cadabra  =  5000,  Shadow_Step = 15 ,Silent_Strike = 40, Berserker_Rage = 15, War_Cry = 40, Fireball = 15}
class Hero:public Character,public Combatable{
    // std::string m_name;                //???????????????????????       
    // int m_health;         
    // int m_attackPower;       
    // int m_defence;         
    int m_XP;              
    int m_level;       
    Item m_item;        
    Ability m_ability;  
protected:
    void setAbility(const Ability& Ability);
    void setItem(const Item& Item);       
public:     
    Hero(const std::string & name);     
    //virtual void displayStats()const = 0;          
    //virtual void takeDamage(int damage) = 0;       
    // virtual void attack(Character* target) = 0;         
    // virtual void useAbility(Character* target) = 0;     
    // virtual void Interact(Character* target) = 0;            
    // virtual void getDialogue() = 0;             
    void addAbility(const Ability&);        
    void changeItem(const Item &);        
};                
       
class Warrior:public Hero {     
    Warior(const std::string &name); 

    //(high health, melee-focused)
};      
class Mage: public Hero {    
    Mage(const std::string& name);
    //(magic-focused, ranged attacks)
      
};
class Rogue:public Hero {     
    Rogue(const std::string& name);
    //(stealth and critical hits).    
};      


#endif         
