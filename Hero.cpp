#include "Hero.h"
class Hero:public Character,public Combatable,public Interactable{
    // std::string m_name;                
    // int m_health;         
    // int m_attackPower;       
    // int m_defence;         
    int m_XP;              
    int m_level;       
    Ability m_ability;        
    Item m_item;        
protected:
    void setAbility(const Ability& Ability);
    void setItem(const Item& Item);
public: 
    Hero(const std:: string & ,int, int, int);     
    //virtual void displayStats()const = 0;          
    //virtual void takeDamage(int damage) = 0;       
    // virtual void attack(Character* target) = 0;        
    // virtual void useAbility(Character* target) = 0;     
    // virtual void Interact(Character* target) = 0;       
    // virtual void getDialogue() = 0;             
    virtual void changeAbility(const Ability&); 
    virtual void changeItem(const Item&); 
       
};    

Hero::Hero(const std:: string & name,int health, int attackPower, int defence):Character(name,health,attackPower,defence) {
   m_XP = 0;
   m_level = 0;
}
void Hero::displayStats()const
{
    Character::displayStats();
    std::cout << "XP:\t" << m_XP << "\nLevel:\t"<< m_level << std::endl;
    std::cout << AbilitytoString(m_ability);
}
void Hero :: takeDamage(int damage)
{
    Character::takeDamage(damage);
}
void Hero:: attack(Character* target){
    target->takeDamage(m_attackPower + static_cast<int>(m_item));
    if(!(isalive())){
     m_XP+ = m_level*20;
    }
}
void Hero:: useAbility(Character * target){
    target->takeDamage(static_cast<int>(m_ability));
}
void Hero:: setAbility(const Ability& Ability){
    m_ability = Ability;
}
void Hero:: setItem(const Item& Item){
    m_item = Item;
}
void changeAbility(const Ability& Ability){
    m_ability = Ability;
}
void changeItem(const Item& Item){
     
    m_item = Item;
}
 
Warrior::Warrior(const std::string & name):Hero(name,150,0,20){
    setAbility(Ability::Berserker_Rage);
    setItem(Item::Ak_47);
}

     
Mage::Mage(const std::string & name):Hero(name,100,0,20){
    setAbility(Ability::Fireball);
    setItem(Item::Magic_Wand);
}

Rogue::Rogue(const std::string& name)::Hero(name,80,0,20){
    setAbility(Ability::Shadow_Step);
    setItem(Item::Knife);
}