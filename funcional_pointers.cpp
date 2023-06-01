#include<iostream>
#include<vector>

void Print(int value) {
    std::cout << value << "\n";

}

void ForEach(const std::vector<int>& values, void(*func)(int)) {

    for(auto i: values) {
        func(i);
    }

}

int main() {

    std::vector<int> values = {1, 2, 3, 4, 5};

    ForEach(values, Print);
    ForEach(values, [](int value){
            std::cout << value << std::endl;
            });
    
}
