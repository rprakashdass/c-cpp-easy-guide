#include <iostream>
#include <thread>

int main() {
    std::cout << "Nmber of threads supported by the hardware " << std::thread::hardware_concurrency() << std::endl;
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread simpleThread([]() {
        std::cout << "Worker thread ID: " << std::this_thread::get_id() << std::endl;
    });
    simpleThread.join();



    std::cout << "Main thread ID again: " << std::this_thread::get_id() << std::endl;

    return 0;
}