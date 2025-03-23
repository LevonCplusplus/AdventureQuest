#include <iostream>
#include "Character.h"
#include "Item.h"
#include <vector>  
class MemoryManagment{
    std::vector<Character*> m_characters;
    std::vector<Item*> m_items;
    std::vector<Quest*> m_quests;
public:
   ~MemoryManagment(){

    for(int i{}; i < m_characters.size(); ++i )
    {
        delete m_characters[i];
    }
    for(int i{}; i < m_items.size(); ++i )
    {
        delete m_items[i];
    }

   }
};