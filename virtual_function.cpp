#include<iostream>
#include<string>

// You want be able to create a instance of the class since it has a pure virtual function
// PureVirtualExample
//
class Entity {
    public:
        std::string GetName() { return "Entity"; }

        virtual std::string GetName1() { return "Entity"; }
        // pure virtual function
        
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

    std::cout << "None virtual function: " << e->GetName() << std::endl;

    std::cout << "Virtual function: " << e->GetName1() << std::endl;

    std::cout << "pure virtual function: " << e->PureVirtualExample() << std::endl;
}

int main() {

    Player* p = new Player("Joan");

    // to explain this is a more better way lets create a function 
    // that takes a entity and print name
    PrintName(p);

    // to fix the above problem we can mark the function as virtual
}

