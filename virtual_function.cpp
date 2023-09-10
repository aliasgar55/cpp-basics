#include<iostream>
#include<string>

// You want be able to create a instance of the class since it has a pure virtual function
// PureVirtualExample
//
class Entity {
    public:
        // cannot override 
        std::string GetName() { return "Entity"; }

        // this can be overriden, but not required
        virtual std::string GetName1() { return "Entity"; }

        // pure virtual function, this makes the call abstract, 
        // meaning that we cannot create a instance of the class
        virtual std::string PureVirtualExample() = 0;
};

class Player : public Entity {

    std::string m_Name;

    public:
        Player(const std::string& name) 
           : m_Name(name) {}
         
        std::string GetName() {
            return m_Name;
        }

        std::string GetName1 () override {
            return m_Name;
        }

        std::string PureVirtualExample() {
            return m_Name;
        }
};

void PrintName(Entity* e) {

    std::cout << "function from entity: " << e->GetName() << std::endl;

    std::cout << "Virtual function: " << e->GetName1() << std::endl;

    std::cout << "pure virtual function: " << e->PureVirtualExample() << std::endl;
}

int main() {

    Player* p = new Player("Joan");

    PrintName(p);
    // output:
    // function from entity: Entity
    // Virtual function: Joan
    // pure virtual function: Joan


}

