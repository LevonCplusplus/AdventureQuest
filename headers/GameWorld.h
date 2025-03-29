#ifndef GAMEWORLD_H
#define GAMEWORLD_H
#include "Character.h"
#include "Hero.h"
#include "Monster.h"
#include "NPC.h"
class Character;
class Hero;
class Monster;

class Location {
    std::string m_name;
    std::string m_text;
    std::vector<Character*> m_entities;
public:
    Location(const std::string& name, const std::string& text) : m_name(name), m_text(text) {}

    void addCharacter(Character* target) {
        m_entities.push_back(target);
    }

    void MoveCharacter(Character* targ) {
        for (size_t i = 0; i < m_entities.size(); ++i) {
            if (m_entities[i] == targ) {
                m_entities.erase(m_entities.begin() + i);
                return;
            }
        }
    }
   void showlocation(){
    std:: cout << "LocName: "<<m_name<<"\t\tAbout Loctaion: "<< m_text<< std::endl;
   }
    Character* givemonster() {
        return m_entities.empty() ? nullptr : m_entities[0];
    }

    bool findhero(Hero* hero) {
        for (Character* entity : m_entities) {
            if (dynamic_cast<Hero*>(entity) == hero) {  
                return true;
            }
        }
        return false;
    }

    std::string& gettext() {
        return m_text;
    }

    std::string& getLocName() {
        return m_name;
    }
    ~Location()
    {
        for(size_t i = 0;i < m_entities.size(); ++i){
            delete m_entities[i];
            m_entities[i] = nullptr;
        }
    }
};


class GameWorld {
    std::vector<Location*> m_locations;

public:
    void addLocation(Location* loc) {
        m_locations.push_back(loc);
    }

    void addworldCharacter(Character* character) {
        m_locations[0]->addCharacter(character);
    }
    void showgameworld(){
        for (size_t i = 0; i < m_locations.size(); ++i) {
            m_locations[i]->showlocation();
        }
    }
    bool ChangeHeroLocation(Hero* hero) {
        for (size_t i = 0; i < m_locations.size(); ++i) {
            if (m_locations[i] -> findhero(hero) && (i < m_locations.size()-1)) {
                m_locations[i] -> MoveCharacter(hero);
                m_locations[i + 1] -> addCharacter(hero);
                return true;
            }
        }
        return false;
    }

    void fightmenu() {
        std::cout << "1. Attack\n" << "2. Use ability\n" << "3. Retreat\n";
    }

    void fight(Hero* hero, Monster* monster) 
    {
        if (!monster) {
            std::cout << "No monster to fight!\n" << std::endl;
            return;
        }

        int h = 0;
        int m = 0;
        std::cout << "You are in a fight with\t"<< monster->getName()<<std::endl;
        

        while (hero->isalive()) {
            monster->showCharacter();
            std::cout << std::endl;
            hero -> showCharacter();
            
            fightmenu();
            int p;
            
            while(true)
            {
                std::cin >> p;
            
                if(p == 1)
                {
                    if (h > 0) {
                        h--;
                    }
                    hero -> attack(monster);
                    break;
                }else if( p == 2 ){
                    if(h != 0){
                        std::cout << "You can't use ability!\n you have to insert another command!!\n";
                        continue;
                    }else{
                        hero -> useAbility(monster);
                        h = 3;
                        break;
                    }

                }else if (p == 3) {
                    std::cout << "You lose!!!\n";
                    return;
                }
            }
            if(!monster->isalive())
            {
                return;
            }
            if (m == 0) {
                monster -> useAbility(hero);
                m = 4;
            } else {
                monster -> attack(hero);
                m--;
            }
                
        }        
    
    }


    bool actionfunc(Hero* hero) {
        for (size_t i = 0; i < m_locations.size(); ++i) {
            if (i == 0) {
                m_locations[i]->showlocation();
                NPC* npc = dynamic_cast<NPC*> (m_locations[i]->givemonster());
                if (npc) {
                    int k;
                    std::cin >> k;
                    std::cout <<std::endl;
                    if(k == 1)
                        std::cout<< npc->getDialogue() << std::endl;
                    else
                    return false;
                }
                continue;
            } else if (i == 1) {
                m_locations[i]->showlocation();
                Monster* monster = dynamic_cast<Monster*>(m_locations[i]->givemonster());
                if (monster) {
                    fight(hero, monster);
                    if(hero -> isalive()){
                        std::cout << "You won this fight with" << monster ->getName()<<std::endl;
                       
                    }
                    else {
                        std::cout<<"you loose";
                        exit(-1);
                    }
                }
            }

            if (ChangeHeroLocation(hero)) {
                // std::cout<<"next location";
                continue;
            } else {
                std::cout << "This location is completed\n";
                return true;
            }

        }
        return true;
    }

    void moveworldCharacter(Character* targ, Location* loc) {
        loc->MoveCharacter(targ);
    }

    ~GameWorld(){
        for(size_t i = 0;i < m_locations.size(); ++i)
        {
            delete m_locations[i];
            m_locations[i] = nullptr;
        }
    }
};
#endif
