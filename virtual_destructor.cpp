#include<iostream>
class Base {
public:
   Base() {std::cout << "Base constructor" << std::endl;} 
   ~Base() {std::cout << "Base Destructor" << std::endl;}  // case 1
   // virtual ~Base() {std::cout << "Base Destructor" << std::endl;} // case 2
};

class Derived: public Base {
public:
    Derived() {std::cout << "Derived Constructor" << std::endl;}
    ~Derived() {std::cout << "Derived Destructor" << std::endl;}

};

int main() {
    Derived* derived = new Derived();
    delete derived;
    std::cout << "--------------------------------------------\n";
    Base* derived1 = new Derived();
    delete derived1;
}

