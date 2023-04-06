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


