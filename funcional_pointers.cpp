#include<iostream>
#include<vector>
#include<functional>

void Print(int value) {
    std::cout << value << "\n";

}


void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {

    for(auto i: values) {
        func(i);
    }
}

/*
void ForEach(const std::vector<int>& values, void(*func)(int)) {

    for(auto i: values) {
        func(i);
    }
}
*/

int main() {

    std::vector<int> values = {1, 2, 3, 4, 5};

    ForEach(values, Print);

    // Using Lambdas
    int a = 50;
    ForEach(values, [&](int value){
            if (a == 50) {
                std::cout << "a is 50" << std::endl;
            }
            std::cout << value << std::endl;
            });
}
