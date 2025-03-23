class NPC:public Interact{
   std::string m_name;
   std::string m_dialogue;
public:
    NPC(const std::string& name):m_name(name){}
    virtual ~NPC() = default;
    
    virtual void displayStates(){
      std::cout << "Name:\t" << m_name << "\nDialoge\t" << m_dialogue << std::endl;
    }

    void Interact(Character* target){
       std::cout << dynamic_cast<Hero*>(target)->getDialogue();
    }

    void getDialogue(){
        retrun m_dialogue;
    }

};
class Villager{
public:
  Villager()NPC("Villager"){
    m_dialogue = "Monsters ! ! !"
  }
};
class Merchant{
public:
    Merchant()NPC("Merchant"){
        m_dialogue = "Need weapons? Armor? Maybe something... exotic?";
    }
};
class Healer{
public:  
 Healer()NPC("Healer"){
    m_dialogue = "Rest now, your wounds will heal in time."
}
};