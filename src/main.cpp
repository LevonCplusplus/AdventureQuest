#include "QuestManager.h"

int main(){
    
    QuestManager* Game = QuestManager::createQuestManager();
    Game->mainmenu();
    delete Game;
    return 0;



    
}
