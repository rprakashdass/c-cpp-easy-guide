
#include<iostream>
#include<thread>
#include<print>
#include<queue>
#include<mutex>
#include<condition_variable>
using namespace std::chrono_literals;

int capacity = 10;
std::queue<std::string> messageQueue;

std::mutex mtx;
std::condition_variable cv;


void writer() {
    int a = 1;
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        std::string message = "message " + std::to_string(a++);
        
        cv.wait(lock, [] {
            return messageQueue.size() < capacity;
        });
        
        messageQueue.push(message);
        std::this_thread::sleep_for(2000ms);
        std::cout << "[WRITER] Write message -> " << message << std::endl;

        lock.unlock();
        cv.notify_all();
    }
}

void reader() {
    while(true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, []{
            return !messageQueue.empty();
        });

        std::cout << "[READER] Read message <- " << messageQueue.front() << std::endl;
        messageQueue.pop();
        std::this_thread::sleep_for(2000ms);

        lock.unlock();
        cv.notify_all();
    }
}

int main() {
    std::thread write(writer);
    std::thread read(reader);

    write.join();
    read.join();
}