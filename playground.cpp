#include<iostream>

int main() {
    int size;
    std::cin >> size;
    int stackArray[size];

    for(auto i: stackArray) {
        std::cout << i << ", " << std::endl;
    }

}
