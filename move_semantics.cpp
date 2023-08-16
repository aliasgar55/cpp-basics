#include<iostream>
#include<string>
#include<cstring>


// a string classs to represent the move semantics demo
class String {
public:
    String() = default;

    // constructor
    String(const char* string) {
        std::cout << "created" << std::endl;
        m_size = strlen(string);
        m_data = new char[m_size + 1];
        memcpy(m_data, string, m_size);
    }

    // copy constructor
    String(const String&  other) {
        std::cout << "copied" << std::endl;
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }
    // constructor that takes a temp value or a r-value reference
    String(String&&  other) noexcept {
        std::cout << "moved" << std::endl;
        // move the data from the r-value to the actual class
        m_size = other.m_size;
        m_data = other.m_data;

        // delete the orignal data 
        other.m_data = nullptr;
        other.m_size = 0;
    }

    // assignment opertor overload of r-value ref
    String& operator=(String&& other) noexcept {
        
        if (&other != this) {
            std::cout << "moved = operator" << std::endl;
            // since we are overriding the current object with the other, we need to make sure that we delete the old data
            // that might be there in the current object, else it will lead to memory leak
            delete[] m_data;
            // move the data from the r-value to the actual class
            m_size = other.m_size;
            m_data = other.m_data;

            other.m_size = 0;
            other.m_data = nullptr;
        }
        return *this;
    }

    void PrintString() {
        std::cout << m_data <<  std::endl;
    }
        
    // destructor
    ~String() {
        std::cout << "Destroyed: " <<  std::endl;
        delete[] m_data;
    }
private:
    uint32_t  m_size;
    char* m_data;
};

class Entity {
public:

    // create a constructor
    Entity(const String& name)
        :m_name(name) {}

    // constructor that takes a r-value reference
    // this call the move constructor in the string class
    Entity(String&& name)
        :m_name(std::move(name)) {}
private:
    String m_name;
};


int main() {
    // create a entity class and see that it call the move constructor
    // Entity e = Entity("Hello");
    // here we are creating a string hello, and copying the data to dest, 
    String apple = "apple";
    {
        String orange = "orange";
        apple = std::move(orange);
    }
    apple.PrintString();
    // in order to move the hello string to dest instead of copying we can use a move = operator
    // this syntax is not supported right now, since we dont have assignment operator overload for r-value reference
    // String dest = std::move(hello);
    // so lets do the constructor way
    // now let do it using the assigment operator way


}
    
