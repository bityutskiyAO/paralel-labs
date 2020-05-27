//
// Created by 17491433 on 27.05.2020.
//

#include "ThreadSaveQueue.h"

void ThreadSaveQueue::savePushBack(const int value) {
    std::lock_guard<std::mutex> lock(locker);
    safetyQueue.push(value);
    std::cout << "Thread №" << std::this_thread::get_id() << " pushed element: " << value << std::endl;
}

ThreadSaveQueue::ThreadSaveQueue() = default;

void ThreadSaveQueue::savePopBack() {
    if (!safetyQueue.empty()) {
        std::lock_guard<std::mutex> lock(locker);
        int result = safetyQueue.front();
        safetyQueue.pop();
        std::cout << "Thread №" << std::this_thread::get_id() <<" pop element: " << result << std::endl;
    } else {
        std::cout << "Thread №" << std::this_thread::get_id() << " try to pop empty stack" << std::endl;
    }
}

int ThreadSaveQueue::saveTop() {
    if(!safetyQueue.empty()) {
        std::lock_guard<std::mutex> lock(locker);
        int result = safetyQueue.front();
        std::cout << "Thread №" << std::this_thread::get_id() << "access to top element: " << result << std::endl;
        return result;
    } else {
        std::cout << "Thread №" << std::this_thread::get_id() << " try to top empty stack" << std::endl;
        return -1;
    }
}

std::queue<int> ThreadSaveQueue::getQueue() {
    return safetyQueue;
}

std::thread ThreadSaveQueue::pushThread(int value) {
    return std::thread([=] { savePushBack(value); });
}

std::thread ThreadSaveQueue::popThread() {
    return std::thread([=] { savePopBack(); });
}

std::thread ThreadSaveQueue::topThread() {
    return std::thread([=] { saveTop(); });
}
