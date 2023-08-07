#include<iostream>

class Base {
public:
    Base() {}
    virtual ~Base() {}
};
class Derived : public Base {
public:
    Derived(){}
    ~Derived(){}
    
};
class Another: public Base {
public:
    Another(){}
    ~Another(){}
};

int main() {
    // static type casting
    int a = 5;
    /*
    double value = (int)5;
    */

    double value = static_cast<int>(5);
    double s = value + a;   

    // reinteprest cast
    // This adds compile time checking, as compared to c style cast
    // Here we are typing to read the memory address of s as Another class pointer
    Another* s1 = reinterpret_cast<Another*>(&s);
    // use of dynamic cast
    Derived* derived = new Derived();
    Base* base = derived;
    Another* ac = dynamic_cast<Another*>(base);
    // Derived* ac = dynamic_cast<Derived*>(base);

    if (!ac) {
        std::cout << "Base variable cannot be typecasted to Another" << std::endl;
    }
    // if we want to check



}
