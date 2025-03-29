#include "GameWorld.h"
class Gameworld;
class Character;
class QuestManager;
class Quest{
  
    GameWorld* m_world;
    Hero* m_hero;
public:

   Quest () = default;
   Quest (GameWorld* game):m_world(game){}; 
   void addQuestCharacter(Character* hero){

        m_world->addworldCharacter(hero);
        
   }
   void showquest()
   {
    m_world->showgameworld();
   }
   void initHero(Hero* hero){
      m_hero = hero;
   }
   bool Questcompleting(){
      return m_world->actionfunc(m_hero);
   }
   ~Quest(){
    //   delete m_hero;
    //   m_hero = nullptr;
      delete m_world;
      m_world = nullptr;
   }
//    void showquest(){
//         std::cout <<"Location: " << m_quest[0].getLocName<< std::endl << "Quest: " << m_quests[0].gettext();
//         m_quest.erase(m_quest.begin());
//    }
};