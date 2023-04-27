#include<iostream>
#include<typeinfo>

int main() {
    const char name[10] = {'h', 'e', 'l'};
    std::cout << (sizeof(name)/sizeof(char)) << std::endl;
    std::cout << typeid("asdf").name() << std::endl;
    std::cout << *name << std::endl;
    std::cout << &name << std::endl;
    const char* name2 = "hello";
    std::cout << typeid(name2).name() << std::endl;
    std::cout << sizeof(name2) << std::endl;
    std::cout << &name2 << std::endl;
    std::cout <<*((name2) + 1)  << std::endl;
    std::cout << name;
} 

