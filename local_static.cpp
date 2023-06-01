#include<iostream>

void Function() {
    static int i = 0;
    int j  = 0;
    j++;
    i++;
    std::cout << "static: " << i << std::endl;
    std::cout << "non static: " << j << std::endl;
}

// using static makes the lifetime of the variable forever but also dosent let other
// part of the program access it
// So in laymans term, here i is initialized just once to zero, and after every
// subsequent calls to the Function we just increment i
int main() {
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
    Function();
}
