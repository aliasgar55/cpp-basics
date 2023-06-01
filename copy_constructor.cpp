// A Program to show an example of copy constructor
#include<iostream>
#include<string>
#include<cstring>

class String {
    private: 
        char* m_Buffer;
        unsigned int m_Size;
    public:
        String(const char* string) {
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, string, m_Size);
            }
        
        String(const String& other)
            :m_Size(other.m_Size) {
                std::cout << "copy constructor called" << std::endl;
                m_Buffer = new char[m_Size + 1];
                memcpy(m_Buffer, other.m_Buffer, m_Size+1);
                
            }


        char& operator[](unsigned int index) {
            return m_Buffer[index];
        }

        friend std::ostream& operator<<(std::ostream& stream, const String& string);

        ~String() {
            delete[] m_Buffer;
        }
};

void PrintString(const String& a) {
    // Here if we pass the argument as String a that leads to the copy of the string
    std::cout << a << std::endl;
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer;
    return stream;
 }

int main() {
    String name = "Cherno";
    String name2 = name;
    name[2] = 'a';
    PrintString(name);
    PrintString(name2);

        

}

