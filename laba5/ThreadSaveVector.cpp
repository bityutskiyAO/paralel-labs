//
// Created by 17491433 on 27.05.2020.
//

#include "ThreadSaveVector.h"


ThreadSaveVector::ThreadSaveVector() {
    std::vector<int> vec(0);
    safetyVector = vec;
}

void ThreadSaveVector::savePopBack() {
    std::lock_guard<std::mutex> lock(locker);
    if(!safetyVector.empty()) {
        std::cout << "Thread №" << std::this_thread::get_id() << " delete element" << std::endl;
        safetyVector.pop_back();
        printVector();
    } else {
        std::cout << "Thread try to pop empty vector." << std::endl;
    }
}

int ThreadSaveVector::saveGetElement(const int index) {
    std::lock_guard<std::mutex> lock(locker);
    if(index < safetyVector.size()) {
        std::cout << "Thread №" << std::this_thread::get_id() << " get element №" << index << ": " << safetyVector[index] << std::endl;
        return safetyVector[index];
    } else {
        std::cout << "Thread try to get nonexistent element from vector" << std::endl;
        return -1;
    }
}

std::vector<int> ThreadSaveVector::getVector() {
    return safetyVector;
}

void ThreadSaveVector::printVector() {
    std::cout << "Print vector: " << std::endl;
    for (int i : safetyVector) {
        std::cout << i <<  " ";
    }
    std::cout << std::endl;
}

void ThreadSaveVector::savePushBack(int value) {
    std::lock_guard<std::mutex> lock(locker);
    std::cout << "Thread №" << std::this_thread::get_id() << " push element: " << value << std::endl;
    safetyVector.push_back(value);
}

std::thread ThreadSaveVector::pushThread(int value) {
    return std::thread([=] { savePushBack(value); });
}

std::thread ThreadSaveVector::popThread() {
    return std::thread([=] { savePopBack(); });
}

std::thread ThreadSaveVector::getElementThread(int index) {
    return std::thread([=] { saveGetElement(index); });
}
