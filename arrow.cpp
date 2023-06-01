#include<iostream>

class Entity {
    public:
        void Print() const {
            std::cout<< "Hello" << std::endl;
        }
        
        ~Entity() {
            std::cout<< "Delete" << std::endl;
        }
};

class ScopedPtr {
    private:
        Entity* m_Obj;
    public:
        ScopedPtr(Entity* entity)
            :m_Obj(entity)
        {

        }
        ~ScopedPtr() {
            std::cout<< "Delete from scoped" << std::endl;
            delete m_Obj;
        }

        Entity* operator->(){
            return m_Obj;
        }

        const Entity* operator->() const {
            return m_Obj;
        }
};

// code to Offset in the memory of a variable using arrow operator
struct Vector3 {
    char x, y, z;
};

int main() {
    /*
    Entity e;
    e.Print();
    Entity* e_prt = new Entity();
    e_prt->Print();

    */
    const ScopedPtr scoped_e = new Entity();
    scoped_e->Print();

     int offset = (long int)&((Vector3*)nullptr)->z;
     std::cout << offset << std::endl;

    
}
