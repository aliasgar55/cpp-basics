#include<iostream>
// showing how static works inside a class
struct Entity {
    static int x, y;
    void print() {
        std::cout << "x: " << x << " y: " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;
int main() {
    Entity e = Entity();
    /* wrong
    e.x = 1;
    e.y = 2;
    */
    Entity::x = 1;
    Entity::y = 2;

    Entity e2 = Entity();
    Entity::x = 3;
    Entity::y = 3;
    /*
    e2.x = 3;
    e2.y = 4;
    */
        
    e.print();
    e2.print();
};
