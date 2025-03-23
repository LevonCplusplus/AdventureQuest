#ifndef CHARCTER_H
#define CHARCTER_H
#include <iostream>
#include <string>
class Character:public Interactable{
    std::string m_name;
    int m_health;
    int m_attackPower;
    int m_defence;
    //Location * m_location;
public:
    bool isalive();
    Character (const std::string &, int, int, int);
    virtual void displayStats()const = 0; 
    virtual void takeDamage(int damage) = 0;
    virtual ~Character() = default;
};
Character:: Character(const std::string & name, int health, int attackPower, int defence):m_name(name),m_attackPower(attackPower),m_health(health),m_defence(defence){}
void Character:: displayStats()const{
    std::cout << "Name:\t" << m_name << "\nHealth:\t" << m_health << "\nAttack Power:\t" << m_attackPower << "\nDefence:\t" << m_defence << std::endl;
}
bool Character::isalive(){
    if(m_health <= 0)
    {
        return 0;
    }
    else 
    
    return m_health;
}
void Character:: takeDamage(int damage){
    if(damage > defence){
      m_health -= (damage - defence);
    }
}

#endif
