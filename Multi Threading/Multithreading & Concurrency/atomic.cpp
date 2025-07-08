
#include <iostream>
#include <thread>
#include <atomic>

/*
    An atomic variable ensures that operations on it (like read, write, increment)
    are performed as indivisible, thread-safe actions.
    
    It allows multiple threads to access and modify the variable safely,
    without needing explicit locks like mutexes.

    Suitable for simple shared data (e.g., counters) where locking overhead is unnecessary.
*/

int n = 1000;
std::atomic<int> counter;

void increment() {
    for(int i = 0;i < n;i++) {
        counter++;
    }
}

int main() {
    std::thread t1(increment), t2(increment);

    t1.join();
    t2.join();

    // we expect 2000 as thread 1 will increment counter +1000 and thread 2 will increment counter +1000, totally 2000
    std::cout << counter;
}
