// ===================== ThreadPool.h =====================
#pragma once
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <atomic>
#include <iostream>

class ThreadPool {
public:
    explicit ThreadPool(std::size_t numberOfThreads);
    ~ThreadPool();

    void enqueueTask(std::function<void()> task);
    void waitAll();                        // Block until every task is finished

private:
    void workerTask();                     // Worker thread loop

    std::vector<std::thread>               workerThreads;
    std::queue<std::function<void()>>      tasksQueue;
    std::mutex                             taskQueueMtx;
    std::condition_variable                condition;          // Wake workers

    std::atomic<int>                       activeTasks{0};     // Running tasks
    std::condition_variable                tasksDoneCondition; // Wake waitAll
    std::mutex                             waitMtx;            // Protect activeTasks / condition

    bool                                   stop{false};        // Shutdown flag
};

/* ---------- inline implementation ---------- */

inline ThreadPool::ThreadPool(std::size_t numberOfThreads)
{
    for (std::size_t i = 0; i < numberOfThreads; ++i) {
        workerThreads.emplace_back([this] { this->workerTask(); });
    }
}

inline void ThreadPool::enqueueTask(std::function<void()> task)
{
    {
        std::lock_guard<std::mutex> lock(taskQueueMtx);
        tasksQueue.push(std::move(task));
    }
    condition.notify_one();
}

inline void ThreadPool::workerTask()
{
    while (true) {
        std::function<void()> task;

        /* ---- wait for work ---- */
        {
            std::unique_lock<std::mutex> lock(taskQueueMtx);
            condition.wait(lock, [this] { return stop || !tasksQueue.empty(); });

            if (stop && tasksQueue.empty()) return;      // graceful exit

            task = std::move(tasksQueue.front());
            tasksQueue.pop();
            ++activeTasks;                               // task is now active
        }

        /* ---- execute outside lock ---- */
        task();

        /* ---- signal possible completion ---- */
        {
            std::lock_guard<std::mutex> lock(waitMtx);
            --activeTasks;
            if (tasksQueue.empty() && activeTasks == 0)
                tasksDoneCondition.notify_all();
        }
    }
}

inline void ThreadPool::waitAll()
{
    std::unique_lock<std::mutex> lock(waitMtx);
    tasksDoneCondition.wait(lock, [this] {
        return tasksQueue.empty() && activeTasks == 0;
    });
}

inline ThreadPool::~ThreadPool()
{
    {
        std::lock_guard<std::mutex> lock(taskQueueMtx);
        stop = true;
    }
    condition.notify_all();
    for (auto& worker : workerThreads)
        if (worker.joinable()) worker.join();

    std::cout << "All threads have been destroyed\n";
}
// =================== end ThreadPool.h ===================



// ========================= main =========================
#include "ThreadPool.h"
#include <chrono>

int main()
{
    ThreadPool pool(8);

    for (int i = 0; i < 23; ++i) {
        pool.enqueueTask([i] {
            std::cout << "Task " << i << " executed on thread "
                      << std::this_thread::get_id() << '\n';
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }

    pool.waitAll();               // ensure all tasks finish
    std::cout << "Program ended\n";
    return 0;
}
// ======================= end main =======================