#include <iostream>
#include <string.h>
using String = std::string;

class Entity {
    private:
        String m_Name;
    public:
        Entity(): m_Name("Default") {};
        Entity(const String& name): m_Name(name) {};

        const String& getName() {
            return m_Name;
        }
    };


int main() {
    // below line create a entity object by calling default constructor
    // This is the fastest way in cpp to creating a object
    Entity* e;


    {
        Entity entity (String("on stack"));
        e = &entity;
        std::cout << e->getName() << std::endl;
    }
    std::cout << e->getName() << std::endl;
    delete e;
}


