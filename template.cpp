#include <iostream>

template<typename Type> 
void Print(Type value)  {
    std::cout << value << std::endl;
}

template<typename T, int N>
class Array {
    private:
        T m_Array[N];
    public:
        int get_size() {return N;}
        
};

int main() {
    Print(5);
    Print("Ali");
    Print(5.5f);
    Array<int, 5> array;
    std::cout << array.get_size() << std::endl;

}
