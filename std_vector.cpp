#include<iostream>
#include<initializer_list> 
#include<string>


template<typename T>
class Vector {

public:
    Vector(int size) {
        m_size_allocated = size;
        realloc(m_size_allocated);
        size = 0;
    }
    Vector(std::initializer_list<T> values) {
        int i = 0;
        realloc(values.size());
        for (auto& value : values) {
            m_data[i] = value;
            i++;
        }
        m_size = values.size();
    }

    Vector() {
        realloc(2);
    }

    ~Vector() {
        clear();
        ::operator delete(m_data, m_size_allocated * sizeof(T));
        std::cout << "Destroyed vector" << std::endl;
    }
    // for debuggin purpose
    
    const T& operator[](unsigned int index) const  {
        std::cout << "const version" << std::endl;
        return  m_data[index];
    }


    T& operator[](unsigned int index) {
        return  m_data[index];
    }

    void push_back(const T& value) {
        if(m_size >= m_size_allocated) {
            realloc(m_size_allocated + m_size_allocated/2);
        }
        m_data[m_size] = value;
        m_size++;
    }

    void push_back(T&& value) {
        if(m_size >= m_size_allocated) {
            realloc(m_size_allocated + m_size_allocated/2);
        }
        // though value is a r-value but when it enters the function it becomse a l-value so we need to type cast it back into a r-value
        m_data[m_size] = std::move(value);
        m_size++;
    }

    template<typename... Args>
    T& emplace_back(Args&&... args) {
        if(m_size >= m_size_allocated) {
            realloc(m_size_allocated + m_size_allocated/2);
        }
        new(&m_data[m_size]) T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }
        
    void pop_back() {
        if(m_size > 0) {
            m_data[m_size--].~T();
        }
    }
        
    void clear() {
        for(;m_size;) {
            m_data[--m_size].~T();
        }

    }
    
    int size() {
        return m_size;

    }

private:
    unsigned int m_size = 0;
    unsigned int m_size_allocated = 0;
    T* m_data = nullptr;

    void realloc(unsigned int new_size) {

        std::cout << "Triggered vector resize" << std::endl;
        T* new_data = (T*)::operator new(new_size * sizeof(T));

        for (int i=0; i<m_size; i++) {
            new(&new_data[i]) T(std::move(m_data[i]));
            m_data[i].~T();
        }


        ::operator delete(m_data, sizeof(m_size));
        m_data = new_data;
        m_size_allocated = new_size;
    };

};

class Vector3 {
public:
    float x = 0.0f, y = 0.0f, z = 0.0f;
    int* mem_block;
    Vector3() {};

    Vector3(float x, float y, float z)
    : x(x), y(y), z(z) {
        mem_block = new int[5];
        std::cout << "constructor Created" << std::endl;
    }

    Vector3(Vector3& other) = delete;

    Vector3(Vector3&& other)
    : x(other.x), y(other.y), z(other.z) {
        mem_block = other.mem_block;
        other.mem_block = nullptr;
        std::cout << "constructor Moved" << std::endl;
    }

    ~Vector3() {
        delete[] mem_block;
        std::cout << "Destroyed vector3" << std::endl;
    }

    Vector3& operator=(Vector3&& other) {
        std::cout << "Moved " << std::endl;
        delete[] mem_block;
        mem_block = other.mem_block;
        other.mem_block = nullptr;
        x = other.x;
        y = other.y;
        z = other.z;
        return *this;
    }

    Vector3& operator=(const Vector3& other) = delete;
};

int main(){

    if(false) {
        Vector<std::string> vec;
        vec.push_back(std::string("HELLO"));
        Vector<std::string> vec1 = {"Ali", "Asgar"};
    }

    Vector<Vector3> vec;
    {

        Vector3& hello = vec.emplace_back(1.0f, 1.0f, 1.0f);
        vec.emplace_back(1.0f, 1.0f, 1.0f);
        vec.emplace_back(1.0f, 1.0f, 1.0f);
        vec.emplace_back(1.0f, 1.0f, 1.0f);
        vec.emplace_back(2.0f, 1.0f, 1.0f);

        for (int i=0; i<vec.size(); i++) {
            std::cout << vec[i].x << std::endl;
        }
        std::cin.get();
    }
    return 0;
}
