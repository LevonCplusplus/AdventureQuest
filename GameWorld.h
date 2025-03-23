
class Location{
    std:: string m_name;
    std::vector<Character*> m_entities;
public:
    Location (const std::string& name):{
    }
}
class GameWorld{
    std::vector<Location*> m_locations;
public:
  
  void moveCharacter(Character* ,Location *);
}
