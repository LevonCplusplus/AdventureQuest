#ifndef INTERACTABLE_H
#define INTERACTABLE_H
#include "Character.h"

class Character;

class Interactable{
public:
    //virtual void Interact(Character* target) = 0;
    virtual std::string getDialogue() = 0;

};


#endif