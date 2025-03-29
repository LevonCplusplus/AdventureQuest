#ifndef NPC_H
#define NPC_H
#include "Interactable.h"

class NPC:public Interactable,public Character {
   std::string m_name;
protected:
   std::string m_dialogue;
public:
    NPC(const std::string& name):m_name(name){};
    virtual ~NPC() = default;

    virtual void displayStates(){
      std::cout << "Name:\t" << m_name << "\nDialoge\t" << m_dialogue << std::endl;
    }

    void Interact(Character* target){
       std::cout << dynamic_cast<Hero*>(target)->getDialogue();
    }

    std::string getDialogue(){
        return m_dialogue;
    }

};
class Villager:public NPC{
public:
  Villager():NPC("Villager"){
    m_dialogue = "There are monsters in Lolosia! ! !\n";
  }
};
class Merchant:public NPC{
public:
    Merchant():NPC("Merchant"){
        m_dialogue = "Need weapons? Armor? Maybe something... exotic?\n";
    }
};
class Healer:public NPC{
public:  
 Healer():NPC("Healer"){
    m_dialogue = "Rest now, your wounds will heal in time.\n";
}
};
#endif