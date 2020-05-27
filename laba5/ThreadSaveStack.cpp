//
// Created by 17491433 on 27.05.2020.
//

#include "ThreadSaveStack.h"

ThreadSaveStack::ThreadSaveStack() {
    std::vector<int> vec(0);
    std::stack<int, std::vector<int>> stack(vec);
    safetyStack = stack;
}

void ThreadSaveStack::savePush(const int value) {
    std::lock_guard<std::mutex> lock(locker);
    safetyStack.push(value);
    std::cout << "Thread №" << std::this_thread::get_id() << "Pushed element: " << value << std::endl;
}

void ThreadSaveStack::savePop() {
    if (!safetyStack.empty()) {
        std::lock_guard<std::mutex> lock(locker);
        int result = safetyStack.top();
        safetyStack.pop();
        std::cout << "Thread №" << std::this_thread::get_id() <<" pop element: " << result << std::endl;
    } else {
        std::cout << "Thread №" << std::this_thread::get_id() << " try to pop empty stack" << std::endl;
    }
}

int ThreadSaveStack::saveTop() {
    if(!safetyStack.empty()) {
        std::lock_guard<std::mutex> lock(locker);
        int result = safetyStack.top();
        std::cout << "Thread №" << std::this_thread::get_id() << "access to top element: " << result << std::endl;
        return result;
    } else {
        std::cout << "Thread №" << std::this_thread::get_id() << " try to top empty stack" << std::endl;
        return -1;
    }
}

std::stack<int, std::vector<int>> ThreadSaveStack::getStack() {
    return safetyStack;
}

std::thread ThreadSaveStack::pushThread(int value) {
    return std::thread([=] { savePush(value); });
}

std::thread ThreadSaveStack::popThread() {
    return std::thread([=] { savePop(); });
}

std::thread ThreadSaveStack::topThread() {
    return std::thread([=] { saveTop(); });
}
