#include<iostream>

class Random {
public:
    // Delete the copy constructor 
    Random (const Random&)  = delete;

    // Create a static get method that returns a static instance of the class
    static Random& Get() {
        static Random instance;
        return instance;
    }

    // Static methods that calls the internal methods using the static instance returned by the Get method
    static float Float() {return Get().IFloat();}


private:
    // Actual implementaion of the static members, these methods can access
    // the member functions
    float IFloat () {return m_Number;}
    // Make the constructor private to prevent creation of new instance of the class
    Random() {}
    // other members
    float m_Number = 0.5f;
};

int main() {
    std::cout << Random::Float() <<  std::endl;
}
