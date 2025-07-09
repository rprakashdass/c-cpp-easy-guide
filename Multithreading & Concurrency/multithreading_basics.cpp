#include <iostream>
#include <thread>   // Required for std::thread
using namespace std;

// Function that prints '+' symbol 100 times
void printPlus() {
    for (int i = 0; i < 100; i++) {
        cout << "+";
    }
}

// Function that prints a given symbol 10 times
void printSymbol(char symbol) {
    for (int i = 0; i < 10; i++) {
        cout << symbol;
    }
}

int main() {
    // Creating two threads:
    // - function1 runs printPlus()
    // - function2 runs printSymbol() with argument '['
    thread function1(printPlus);
    thread function2(printSymbol, '[');

    // Wait for both threads to finish execution before exiting main()
    function1.join();
    function2.join();

    // Additional: Launch another thread using a lambda function
    thread function3([]() {
        for (int i = 0; i < 5; ++i) {
            cout << "*";
        }
    });

    // Don't forget to join this thread too!
    function3.join();

    cout << "\nAll threads finished execution.\n";

    return 0;
}
