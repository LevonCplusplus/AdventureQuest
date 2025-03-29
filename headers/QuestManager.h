#ifndef QUESTMANAGER_H
#define QUESTMANAGER_H
#include "Monster.h"
#include <iostream>
#include <vector>
#include "Quest.h"
#include "NPC.h"
class NPC;
class Quest;
class Monster;

class Reward {
public:
    int m_rewXP;
    Item *m_rewitem;

    Reward(int xp, Item *item) : m_rewXP(xp), m_rewitem(item) {}
};

class QuestManager {
    std::vector<Quest *> m_activeQuests;
    std::vector<Quest *> m_completedQuests;
    std::vector<Reward *> m_rewards;
    static QuestManager* m_ptr;

public:
    QuestManager() = default;
    void mainmenu() {
        std::cout << "Welcome to the game Adventure Quest\n\n1. Choose the Hero with whom you would like to take part in our Adventures!!!\n2. Exit\n";
        int p;
        std::cin >> p;

        if (p == 2) {
            return;
        }

        std::cout << "1. Warrior\n2. Mage\n3. Rogue\n";
        std::cin >> p;

        Hero*  hero = nullptr;
        if (p == 1) {
            hero = new Warrior("Warrior");
        } else if (p == 2) {
            hero = new Mage("Mage");
        } else if(p == 3){
            hero = new Rogue("Rogue");
        }else{
            return;
        }

        if (m_activeQuests.empty()) {
            std::cout << "No active quests available!" << std::endl;
            return;
        }
        hero->showCharacter();
        m_activeQuests[0]->addQuestCharacter(hero);
        
        for (size_t i = 0; i < m_activeQuests.size(); ++i) {
            m_activeQuests[i]->initHero(hero);
            if(m_activeQuests[i]->Questcompleting()){
                // m_activeQuests[i]->showquest();
                checkcompletion(m_activeQuests[i]);
                hero->levelup();
                i--;
            }    
            else{ 
                std::cout<<"you lose!!";
                return;
            }
        }
    }

    static QuestManager* createQuestManager() {
        if(!m_ptr){
            QuestManager* Game = new QuestManager();

            GameWorld* world1 = new GameWorld();
            GameWorld* world2 = new GameWorld();
            GameWorld* world3 = new GameWorld();

            Location* loc1 = new Location("Village","You enter the Village\nYou encounter a Villager!\n1. Talk to Villager\n2. Ignore\nChoose an action:");
            Location* loc2 = new Location("Lolosia","A Goblin appears!");
            Location* loc3 = new Location("Battleon","You enter the Battleon\nYou encounter a Merchant!\n1. Talk to Merchant\n2. Ignore\nChoose an action:");
            Location* loc4 = new Location("The Devourers Network","Combat with Troll");
            Location* loc5 = new Location("Frostvale","You enter the Frostvale\nYou encounter a Healer!\n1. Talk to Healer\n2. Ignore\nChoose an action:");
            Location* loc6 = new Location("Darkovia","Combat with Dragon");

            loc1->addCharacter(new Villager);
            loc2->addCharacter(new Goblin("Goblin"));
            loc3->addCharacter(new Merchant);
            loc4->addCharacter(new Troll("Troll"));
            loc5->addCharacter(new Healer);
            loc6->addCharacter(new Dragon("Dragon"));

            world1->addLocation(loc1);
            world1->addLocation(loc2);
            world2->addLocation(loc3);
            world2->addLocation(loc4);
            world3->addLocation(loc5);
            world3->addLocation(loc6);

            Quest* quest1 = new Quest(world1);
            Quest* quest2 = new Quest(world2);
            Quest* quest3 = new Quest(world3);

            Game->addQuest(quest1);
            Game->addQuest(quest2);
            Game->addQuest(quest3);
            m_ptr = Game;
        }
        return m_ptr ;
    }

    void addQuest(Quest* quest) {
        m_activeQuests.push_back(quest);
    }

    void checkcompletion(Quest* p) {
        for (size_t i = 0; i < m_activeQuests.size();++i){
            if(p == m_activeQuests[i]){
               m_completedQuests.push_back(m_activeQuests[i]);
               m_activeQuests.erase(m_activeQuests.begin()+i);
            }
        }
    }
    void showGame(){
        for (size_t i = 0; i < m_activeQuests.size(); ++i) {
             m_activeQuests[i]->showquest();
             
        }
    }
    ~QuestManager(){
        for(size_t i = 0; i < m_activeQuests.size(); ++i){
            delete m_activeQuests[i];
            m_activeQuests[i] = nullptr;
        }
        for(size_t i = 0;i < m_completedQuests.size(); ++i)
        { 
           delete m_completedQuests[i];
           m_completedQuests[i] = nullptr;
        }
         m_ptr = nullptr;
    }
};
QuestManager* QuestManager::m_ptr = nullptr;

#endif
