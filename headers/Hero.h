#ifndef HERO_H
#define HERO_H

#include "Character.h"


class Character;
class Combatable;
class Quest;
class Interactable;


enum class Item {Knife = 15, Kerambit = 30, Magic_Wand = 20, Dragon_Sword = 40, Ak_47 = 30, Igla = 60};
enum class Ability {Abra_Cadabra = 5000, Shadow_Step = 15, Silent_Strike = 40, Berserker_Rage = 15, War_Cry = 40, Fireball = 15};

class Hero : public Character, public Combatable, public Interactable {
    int m_XP;              
    int m_level;       
    Item m_item;        
    Ability m_ability;  

protected:
    void setAbility(const Ability& ability);
    void setItem(const Item& item);       

public:     
    Hero(const std::string& name, int health, int attackPower, int defence);  
    void addAbility(const Ability& ability); 
    void displayStats() const ;   
    //virtual void Interact(Character* target) ;
    void levelup();
    virtual std::string getDialogue() ;
    void takeDamage(int damage); 
    void changeItem(const Item& item);   
    void attack(Character* target);
    void useAbility(Character* target);     
};                
       
class Warrior : public Hero {   
public:  
    Warrior(const std::string &name);
};      

class Mage : public Hero {
public:    
    Mage(const std::string& name);
};      

class Rogue : public Hero {     
public:
    Rogue(const std::string& name);
};      

#endif
