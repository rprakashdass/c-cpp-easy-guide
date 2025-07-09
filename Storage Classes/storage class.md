# Storage class
    - Storage class defines the scope, lifetime, visibility and linkage of variables or functions
    - In other words, it tells the compiler:
        - Where the variable is stored
        - How long it lives (lifetime)
        - Where it can be accessed (scope)
        - Whether it can be used in other files (linkage)
  
## List of Storage Classes in C++
Keyword	Scope	Lifetime	Linkage	Use Case
auto	Block	Local	None	Type inference (modern C++)
register	Block	Local	None	Suggest keeping in CPU register (obsolete)
static	Block/File	Entire program	Internal	Preserve value across function calls / restrict linkage
extern	File	Global	External	Refer to global variable defined elsewhere
mutable	Class	Object	—	Allow modification in const objects (C++)


# auto 
    - Used for type inference in modern c++
    - It meant automatic storage of variable and functions
  
# register
    - Register stores data in CPU regis ters unlike other storage classes
    - It helps in faster memory access
    - The size of variable is always depens upon the size of register
    - It is depriciated in modern c++ (c++ 11 onwards) and its been optimized by compilers nowadays

# static
    - It declares variable in local scope and provides global lifetime
    - It retain values between function calls inside functions
    - It limits visibility of the file
    - It does internal linkage

# extern
    - It helps to use variables or functions defined in external file

# mutable
    - It allows a non const member variable to be monified even when declared within a const member function.