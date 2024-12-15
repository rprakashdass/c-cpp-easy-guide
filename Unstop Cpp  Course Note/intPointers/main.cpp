#include <iostream>
using namespace std;

int main() {
    int n = 9;             // An integer variable
    int *ptr = &n;         // A pointer to the integer

    cout << "Integer to Pointer" << endl;
    cout << "n = " << n << endl;           // Value of n
    cout << "&n = " << &n << endl;         // Address of n
    cout << "*ptr = " << *ptr << endl;     // Value at the address pointed to by ptr
    cout << "ptr = " << ptr << endl;       // Address stored in ptr

    int **pptr = &ptr;     // A pointer to the pointer ptr
    (*ptr)++;              // Increment the value pointed to by ptr

    cout << "\nPointer to Pointer" << endl;
    cout << "**pptr = " << **pptr << endl; // Value pointed to by the pointer pointed to by pptr
    cout << "*pptr = " << *pptr << endl;   // Address stored in pptr
    cout << "pptr = " << pptr << endl;     // Address of pptr

    // Demonstrate null pointer
    int *nullPtr = nullptr;
    if (nullPtr == nullptr) {
        cout << "\nnullPtr is a null pointer." << endl;
    }

    // Pointer arithmetic
    int arr[3] = {1, 2, 3};
    int *arrPtr = arr; // arrPtr points to the first element of arr

    cout << "\nPointer Arithmetic" << endl;
    cout << "arr[0] = " << *arrPtr << endl;     // Value at arr[0]
    cout << "arr[1] = " << *(++arrPtr) << endl; // Value at arr[1] 
    cout << "arr[2] = " << *(++arrPtr) << endl; // Value at arr[2]

    // Dynamic memory allocation
    int *dynamicPtr = new int(20); // Allocate memory dynamically
    cout << "\nDynamic Memory Allocation" << endl;
    cout << "Value at dynamicPtr = " << *dynamicPtr << endl;
    delete dynamicPtr; // Free allocated memory

    // Array of pointers
    int *ptrArr[3];
    for (int i = 0; i < 3; ++i) {
        ptrArr[i] = &arr[i]; // Store address of each element in the array
    }

    cout << "\nArray of Pointers" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Value at ptrArr[" << i << "] = " << *ptrArr[i] << endl;
    }

    return 0;
}
