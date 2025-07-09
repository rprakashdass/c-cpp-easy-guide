#include <iostream>
#include <thread>

void task(int id) {
    std::cout << "Thread " << id << " is running.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Thread " << id << " finished.\n";
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);
    std::thread t3(task, 3);
    std::thread t4(task, 4);
    std::thread t5(task, 5);

    // Join all threads
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();

    std::cout << "All threads completed.\n";
    return 0;
}
