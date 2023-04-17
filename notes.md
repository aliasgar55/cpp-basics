# TIPS
1. Main function is a special function it return 0 if you dont return anythin
2. TIP: Think of operators as function
3. Each file of cpp is converted to and .obj file and linker bundels all these files into a excutable binary (linker job is to resolve symbols)
4. Statments that starts with # are preporcessor statments
5. Different types of preporcessor are, "include, define if"
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
4. If you want to write really fast code, try to avoid if else conditions
# FOR LOOPS AND WHILE LOOPS
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

// refrence 
int main() {
    int a = 5;
    increment();
    cout << a; // 6
}

void increment(int& ref) {
    ref++;
}
```
5. Intresting facts about ref
    - You cannot change what a reference refers too 
    - which means when declaring a refrence it has to be assigned to something

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

