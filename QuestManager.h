#ifndef QUESTMANAGER_H
#define QUESTMANAGER_H
#include "Quest.h"
class Reward{
    int m_rewXP;
    Item * m_rewitem;
}
class QuestManager{
    std::vector<Quest*> m_activeQuests;
    std::vector<Quest*> m_completedQuests;
    std::vector<Reward*> m_rewards;


}


#endif