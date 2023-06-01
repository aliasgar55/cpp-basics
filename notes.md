# TIPS
1. Main function is a special function it return 0 if you dont return anythin
2. TIP: Think of operators as function
3. Each file of cpp is converted to and .obj file and linker bundels all these files into a excutable binary (linker job is to resolve symbols)
4. Statments that starts with # are preporcessor statments
5. Different types of preporcessor are, "include, define if"
6. Chars are useful to do pointer arithmatics since they represent 1 byte of memory
# LINKER
1. linker job is to link different obj file into one exe file
# VARIABLES
1. Used to store data
2. they occupy memory
3. The only real difference between the datatypes is how much memory they occupy
4. char and bool are 1 byte, short is 2 byte, long is 4 byte, long long 8 byte
5. way to store decimal is using double(8 byte) or float(4 byte)
6. NOTE: bool require 1 byte and not 1 bit, since we cant access a bit in the program
   so we have to use 1 byte. We can do some tricks to store 8 bools in 1 byte
7. sizeof operator prints the size of the variable
# FUNCTIONS 
1. Syntax <return  type> <function name>([arguments]...) {[body]}
2. calling a function syntax: <function name>([arguments]...)
3. The primary point of function is to prevent duplication of code
# HEADER FILES
1. Header files are mostly used for declaration, so that one can get access to
   functions defined in other files
2. These files are included using #include preprocessor which basically copy and
   pastes the code from the header file to the line where its included
3. #pragma once is a header guard to prevent the header file from being included   
   twice in the same code
4. to include the header file relative to the current file use ("") 
# IF AND ELSE CONDTIONS
1. if conditions execute code if some conditions are matched
syntax:
```
if () {}
else {}
```
2. If conditions can slow down your code because of jumping betweein the actual
   code instructions at assembly level 
3. There is no else if in cpp, its justs a syntax sugar and behind the hood its
   actually if and else 
4. If you want to write really fast code, try to avoid if else conditions # FOR LOOPS AND WHILE LOOPS
1. There are 3 type of loops for loop, while loop and do while loops
2. These loops are used to perform a action multiple times based on some condition
3. Syntax for loops are 
```
for(init; condition; action){}
while(condition){}
do{}
while(condition){}
```
# CONTROL FLOW STATMENTS
1. break, continue, and return are control flow statments
2. If a continue is encountered in a loop, it goes into the next iteration
   without going in to the remaining part of the loop
3. If break is encountered the code exits the loop
4. If return is encountered it exits the function
# POINTERS
1. Pointers are a data type that is used to store memory address of a memory 
   block
2. In laymans term pointers are a variable of int datatype
3. You can create a pointer using int `void* ptr = nullptr
4. Types in pointer are just syntax sugar and it helps us find what datatype is 
   stored at a given memroy address
5. Example of int pointer 
   Here `ptr` stores the address where a is stored in the computers memory
```cpp
int a = 10;
int* ptr = &a;
```
6. To get the values stored at a memory location we use `*` operator
Example: 
```cpp
int a = 10;
int* ptr = &a;
*a = 11;
cout << a; // 11
```
7. Example of how to create and delete memory from heap
```cpp
char* buffer = new char[4]  // create a 8 byte memroy and return a point the the start of it
memset(buffer, 0, 8)
delete[] buffer
```
# REFERENCES
1. References are just pointers in disguise, References are syntax sugar
2. Reference only exits in source code, references dont occupy memrory like a real variable
3. Syntax 
```cpp
int a = 10;
int& ref = a;
ref = 2;
print(a) // 2
```
4. Here are 2 examples of code one using reference and one using pointer
```cpp
// Pointer
int main() {
    int a = 5;
    increment(&a);
    cout << a; // 6
    }

void increment(int* ptr) {
    (*ptr)++;
}

// reference 
int main() {
    int a = 5;
    increment(a);
    cout << a; // 6
}

void increment(int& ref) {
    ref++;
}
```
5. Intresting facts about ref
    - You cannot change what a reference refers too 
    - which means when declaring a reference it has to be assigned to something

OOPS
---
# CLASS
1. Classes allow us to group variables together into a type and also add functionality to it
2. Diffrence between struct and class 
    - Classes are private by default while struct are public by default
    - Struct are there to add backward compatiblity with c
# STATIC-KEYWORD
1. Static keyword is used to mark a variable as static in cpp
2. Static when used inside a class makes all the instance of the class use the same variable
3. While if static is used outside of the class it make the scope of the variable only to the translation unit its defined in
4. if you want a variable to be used across all the instances of a class you can make it static
5. Static method cannot access non-static variables for obvious reasons
6. Static is used of data that we dont want to change between class instances
7. Syntax `static int x = 10;`
## LOCAL STATIC
1. You can make a variable static to a local scope as well, this makes the variable
   declared just once, and use the same instance of the variable to be used across
   subsequest call to the scope/function.
# ENUM
1. Syntax 
```cpp
enum Example : [type] {
    A = 0, B = 1, C = 2
    }
```
2. Note: You can assign a type to the enum to reduce the amount of memory a enum takes
   By default enum type is int taking 32 bits of memory
3. At the end of the day enums are just integers behind the scenes
# CONSTRUCTOR-BASICS
1. Defination: constructor is a special function that run when a instance of a class is initialized
2. Syntax: 
```cpp
ClassName(parameters) {}
```
3. Each class in cpp has a constructor called default constructor
4. If you want to get rid of the default constructor either make it private or 
   `ClassName() = delete;`
5. Note: In language like java and c-sharp all the primitive types are initialized by 
   default, while thats not the case in c++
6. In short basic use of constructor is for initilizing the instance and its memory 
# DESTRUCTOR-BASICS
1. Destructor is called when a instance of a class cleared away
2. Syntax
```cpp
~ClassName() {}
```
3. Primary use of destructor is to delete the memory allocated for the instance of the class
4. Real world examples are: if you have heap allocated objects, you can delete it in the destructor
5. You can also call a destructor manually.
# INHERITANCE 
1. A class can have heirarcy, it can inherinit variables and methods from another class 
2. Inheritance is useful in getting the functionality of a class that it inherits, preventing code duplication
3. Syntax 
```cpp
class Entity {}
class Player : public Entity {}
```
4. The above example Player class inherits the Entity class
5. If there is a function that takes entity, we can pass player class instance and the code will work.
   This is because Player class will always have everything entity has, this pheonamena is called polymorphism
# VIRTUAL FUNCTIONS
0. Virtual function allow us to override methods in base class
1. Please refer to virtual_function.cpp for example 
2. Note: Virtual functions are not free, there is a performance penelty associated with virtual functions
   firstly there is need for extra memory, to store the v_table and a pointer to the v table is stored in the base class,
   and every time we call a virtual function we have to go through the v_table to determine which function to call, so there is a 
   extra jump in the execution, this only becomes a issues when we are working on some embedded system or similar, other than that
   its not an a issue
3. Virtual function use something called diyamic dispatch which is implemented using v_table
## PURE VIRTUAL FUNCTION
1. This is similar to abstract method or interface in java or c-sharp
2. Syntax for pure virtual function is `vitual int function_name() = 0;`
3. You cant create an instance of a class that has a pure virtual function
4. A pure virtual function is a function that dosent have a body, body of this function is defined in a function inheriting it
# VISIBLITY
1. visiblity is used to restrict the access of members and methods of a class by other code
2. there are 3 types of visiblity in c++, private, protected, and public
3. Private: only the code inside the class can access the variable, there is a exception for firend
4. Protected: Only the class itself and the class inheriting the class can access the variables and methods
5. Public: Anyone can access it
# ARRAYS
1. Array is a group of variables stored in a single row in a memoroy
2. Declaration `int array[5]` this is a declaration on stack
3. you can access a values from array using `array[0]`, if you try to access value of bounds
   you will get a MemoryViolation error in debug mode, but you might not get that error in 
   production
4. array is just a pointer 
5. `array[2]` can be rewirtten as with *(array + 2), this is possible because 
    arrays are stored in contiguious block memory
6. we can also create arrays on heap `int* another = new int[5];`
7. Array created on heap will be there untill the program ends or we manually delete it
   from the code `delete[] another`, diffrence between heap and stack allocated arrays are lifetimes
8. We have to maintain size of a heap allocated memory in cpp, also there is a jumping around with heap allocated memory
   so its has a performance overhead
9. To overcome this issue we have array datastructure introduced in c++11 library, which does built in bound checking
   and also has a size variable, to keep track the size of array, and it also has a performance overhead becuase of all the 
   additional features
# STRINGS
1. A string in a array of characters in cpp
2. To define a string you can do `const char* name = "Joan"` or `std::string name = "John"`
3. A const char* ends to a null character `\0` to denote end of the string
4. Standard c++ library for string has many operation for string
5. TIP: dont pass class directly to a function this creates a copy of the string instead pass a reference
6. More points comming soon....
# CONST
1. const is a keyword in cpp, that is used to add restriction to the code on how it 
   can modify certain variable or data
2. adding a const dosent change how a code will run actually, but instead it enforces some rules    
   on the developer writing the code
3. Syntax `const int a = 2`
4. addint const to a varible in this way prevent it from being modified in other part of the code
   making it readonly
5. const with pointer works in 2 ways either change the pointer it points to or the contents of the the pointers
6. To prevent modification of the content of the pointer use `const int* a = new int`, to prevent modification
   of the location where pointer points to use `int* const a = new int`, and to prevent both the cases use const
   on both the places(tip: here the position of const is relative to * symbol)
7. const with methods: if const is added to a method in a class like `int get_x() const {}`(on the right side of the method name) this means
   that the method is not going to modify the class it will just read the contents of the class 
# MUTABLE
* Mutable with const
 1. If mutable keyword is added before a variable, this gived the const class methods to modify
    this variable
* Mutable with lambda
 1. Adding mutable keyword to a lambda function lets the lambda function modify that variable
    ```cpp
    // NOTE: Here = means that you are passing the value
    // You can replace = with & to pass the argumentes as refrence instead
    int x = 0;
    auto f = [=]() mutable {
        x++; // this would not have been possible without mutable keyword
    }

    // value of x here is still 8, mutable keyword just created a copy internally to make your code cleaner,
    auto f [=]() {
        int a = x;
        return a++;
        // Note here wer are not modifying x but instead creating a and chainging that
    }
    ```
# MEMBER INTIALIZER LIST
0. Intializer list is an alternative to intializing variables using constructor
1. Syntax  
```cpp
class Entity {
    std::string m_Name = new std::string 
    Entity(): m_name("default") { }
    Entity(std::string Name): m_name(Name) { }
```
2. In the above example m_Name will be initialized to Default, any values supplied by user
3. The benefit of the member initializer list is not just limited to, better syntax and clean constructor,
   but also have performace advantage if a member variable is not listed in the initializer list, then its 
   initialized 2 times, once were its declared, and once in the constructor, if 
   its declared in the member initalizer list then its only intialized once
4. NOTE: It dosent matter the order in which you list the members in the constructor,
   they will be initailized in the order in which they are declared in the class,
   if not followed this can lead to dependency problems, so make sure to write the list in 
   the same order as declared
   Example of incorrect order of initializer list, here m_score should come first since 
   its declared first
```cpp
   class Entity {
       private:
           int score m_score;
           std::string m_name;
       public:
           Entity(): m_name("Default"), m_score(0)  {}
   };
```
# TERNERY OPERATOR
1. Syntax `value = (if ? this : this_one)`
2. Terynary operator is a way to write if else condition in a different way
# WAYS OBJECTS ARE STORED IN CPP
1. there are 2 types of memory to alocate memory to a object, stack and on heap
2. to alocate memory on heap use new `Entity* e = new Entity()` keyword and to delete the object from the 
   use delete keyword `delete e`
3. Always try to allocate memory on stack since its faster and self managed, only allocate 
   objects on heap when your object is too large for stack memory or you want to manage the lifetime of your object
# UNDERSTANDING NEW KEYWORD
1. In cpp new keyword is used to allocate memory on heap
2. New keyword is a operator which calls a function(malloc) and passes the size argument
   and returns a pointer to the block on memory allocated, new keyword also calls the constructor
3. If new keyword is used we need to use delete keyword to free the memory, that was allocated by new 
# IMPLICIT AND EXPLICIT CONVERSION
1. To be added soon...
# OPERATOR OVERLOADING
1. Operator Overloading is used to use a operator like + or - to be used as function
2. For example if there is a code like `3.add(4)` we can overload + operator with add function and 
   write this code as `3 + 4`
3. Syntax: 
```cpp
int operator+(int a) {
    return class.x + a
    }
```
4. Note: Operator overloading is just like writing a function, and just because 
   you can overload a operator dont do it unless it makes perfect sense and the operator
   is very intutive to use, because this can make your code harder to understand and reason about
# THIS KEYWORD
1. `this` is a keyword in cpp that is used to reference the instance of the class inside the class method 
    or member function
2. the keyword becomes useful for example if you want to call a function outside of the class and that function 
   takes the refrence of the class as a argument then you can pass *this and call the function
3. Below is another example, of this being used in constructor
```cpp
class Entity {
    int x, y;
    public
        Entity(int x, int y) {
            // note here we cant do x = x since it will reassing x to itself
            this->x = x;
            this->y = y;
        }
}
```
4. Type of this in a member function is `Entity *e` and in a const function is `const Entity *e`
# OBJECTS LIFETIME
1. A scope can be anything a function a if block etc..
2. Stack and  Heap are 2 type of memory allocation strategy used in cpp
3. A stack based variable is destroyed when the variable goes out of scope
4. A very good example levaraging stack based lifetimes, are unique pointers, scoped locks etc
# SMART POINTERS
1. There are 3 type of smart pointer, namely unique pointers, shared pointers, weak pointers
2. Unique pointers: Unique pointers are pointers that clears the allocated memory 
   automatically when the pointer goes out of scope
3. Syntax
```cpp
# include <memory>
int main() {
    // syntax 1
    std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    // or
    // syntax 2
    std::uniqye_ptr<Entity> entity(new Entity());
    // syntax 1 is better than 2 since it provides exception safety
    } ```
4. One cannot copy a unique pointer
4. Unique pointers have almost no overhead, unqiue pointers cannot be shared
   between variables, since sharing a unqiue pointer would mean that if one
   goes out of scope and is deleted other pointer pointes to a memory thats not
   valid
5. Shared pointers: Shared pointers are scoped pointers that can be copied they
   work by maintaining a ref count, each time a pointer is copied, the ref
   count increases by 1, and when a shared pointer goes out of scope the ref
   count is decreased by 1. The memory is freed automatically when the ref
   count reaches zero.
6. Shared pointer has a small over, since they matain ref count
7. Weak pointers: Weak pointers are similar to shared pointer, but when a
   shared pointer is gets shared with a weak pointer the ref count dosent
   increase, which means that even if there is a weak pointer to a memory
   address in scope, the memroy will still be freed since shared pointer ref
   count is zero
8. One can ask a weak pointer if its still valid or not
# COPY AND COPY CONSTRUCTOR
1. When you use = operator to assign a object to a variable, it leads to a copy
   of the actual object, compiler creates a new object of the class copies the 
   private members of the from the object to the new object
2. Refer to [copy_constructor.cpp](../copy_constructor.cpp) for a detailed example
# ARROW OPERATOR
1. Arrow operator is used to access the methods and members of a pointer without  
   derefrenceing the pointer.
   Syntax:
   ```cpp
   Entity* e  = new Entity();
   e->x;
2. Refer to [arrow operator](../arrow.cpp) for a detailed example
3. Code to get the offset of a variable in a memory
# VECTORS
1. Vectors are dynamic arrays which means, that you dont need to specify the size
   while initializing, you can add elements as needed, and the array grown dynamically
2. NOTE: The Elements in the array are stored as a single contingous block of memory 
3. Remember: ALways try to pass the vector as reference to a function, else it will
   lead to a complete copy of the vector, this is even true while using vectors in a
   range based for loops, make sure to use ref there as well
4. Optimizing vector class of standard library, code in [optimized vector](./vector.cpp)
5. The way vector works, is that you start with a array, and when you add elements to this array
   and if the size of the underlying array is not enough the another arrray is created
   and the existing elements are copied to the new array
6. Data inside the vectors are stored in heap, and only the metadata of the vector like
   size etc is stored in stack
# USING EXTERNAL LIBRARIES
1. There are 2 ways to link external libraries in cpp using, Dynamic linking and static linking
2. In static linking the library is put into the soruce code
 - Static linking is techinically faster because compiler can perform optimizations
3. Dyanmic linking, means that the library is actually linked at the runtime
4. Lets talk about static linking.
 - We need to get the binaries either in compiled form or in source code and complie it by ourself
 - There are 2 major parts 2 the libary, one is the includes folder that contains the header files i.e function 
   declaration etc, and other is the lib folder that contains the actual implementation
 - Header files tells us what functions are available in the libaray
 - So we need to configure the compiler to point to the header file, and configure the 
   linker to point to the library file
5. Dynamic linking also works very similar to the static linking, we need to add  
   header file, but instead of specifying the lib file, we add a file that has location
   of the functions in the actual dll file, this methods need the dll file to be needed
   before we are able to run the program 
   - There is also another way were, we dont need the dll file and the program can run
     without the dll file, and when it calls a function that is defined in the dll file
     it then needs to search the dll file for the specific function being called
# HOW TO RETURN MULTIPLE VALUES
1. You can return a structure from a function
2. Other way is add the return variables as argument to the function
3. Another way is to return a array, but here each return value needs to be of the same type 
4. One more way is to create a tuple and return
5. Here returning a struct is the most redable code, and taking output arguments as input is the most 
   efficient way 
# TEMPLATES
1. If compared to other languages templates can be compared to generics in c# and cpp
   but are infinitely more powerfull then generics
2. Example of template: if there is a function that can take multiple type of parameters    
   then we can define a template and use the template type instead.
   `template <typename T>` and then we can use it in a function like this `void hello(T value)`
3. The way it works is that when we define a function with a template, and the function dosent actually gets defined
   unless we call it, so based on when we call it and how we call it, based on type the function gets created, 
   and complied
4. So in summary templates gives us the ability to run specific code based on what type we pass
5. Note: The template dosent actually exists untill we call it, so if you have a syntax error in the template
# HEAP vs STACK
1. STACK allocations are a lot faster than help allocation
2. Heap allocation calls new which in turn calls malloc which asks the operating system for the memory
   and does all the book keeping going throught the freelist to find a free memory block 
   and marking the memory as used etc, and returns  the pointer to the memory
3. Here the performance diffrence is the allocation
4. Always try to allocate on stack unless you cant maybe due to size of the data or lifetime
# MACROS
1. Syntax 
```cpp
#define LOG(x) std::cout << x << std:: endl
int main() {
    LOG("Hello")
}
```
2. Macros work by replacing the macro with the actual code during the preproccessing stage in compiling
3. Here is a example of macro used to log in debug mode while ignore it in relase mode
```cpp
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif
```
4. In the above exmple if PR_DEBUG is set to 1 then LOG(x) will print x to the terminal
   else if PR_RELEASE is defined then LOG(x) will be replaced with nothing, this way
   we can use macros, macros are used a lot for debug purpose, or enable or disable some stuff 
5. We can escape a character in macro with a `\`, this way we can write macro in multiple line by escaping a new-line character
# AUTO keyword
1. Auto keyword is used to automatically deduce type of a variable at compile time 
2. `auto x = "hello";` Here the type of x will be const char*
3. we should use auto judiciosly since in can make your code hard to understand and reason
# Standard array std::array
1. Std array in cpp is just a simple c style array with a size attached to it
2. Syntax 
```cpp
std::array<int, 5> a;
a[1] = 1
```
3. Here int is the datatype we need to store, and 5 is the size
4. We should use, std array instead of c style array since it has no overhead, 
   it performs bound checking in debug mode, and can we used with iterators, also
   the size variable is not stored since its a template argument, so no extra memory is required
5. Also the variables are stored on stack as opposed to heap in vectors
# INTRO to functional pointers
1. Functional pointers are a technique in which variables can be assigned to functions
   and the variables can be used to call the actual functions
2. functional pointers are pointers to the actual location of the function in the binary
3. An example of functional pointers can be found in [functional_pointers.cpp](./funcional_pointers.cpp)
# LAMBDAS
1. 
