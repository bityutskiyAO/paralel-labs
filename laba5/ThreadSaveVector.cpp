//
// Created by 17491433 on 27.05.2020.
//

#include "ThreadSaveVector.h"


ThreadSaveVector::ThreadSaveVector() {
    std::vector<int> vec(0);
    safetyVector = vec;
}

void ThreadSaveVector::savePopBack() {
    clock_t start = clock();
    std::lock_guard<std::mutex> lock(locker);
    if(!safetyVector.empty()) {
        std::cout << "Thread №" << std::this_thread::get_id() << " delete element" << std::endl;
        safetyVector.pop_back();
        printVector();
    } else {
        std::cout << "Thread try to pop empty vector." << std::endl;
    }
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    popingTime.push_back(seconds);
}

int ThreadSaveVector::saveGetElement(const int index) {
    clock_t start = clock();
    std::lock_guard<std::mutex> lock(locker);
    if(index < safetyVector.size()) {
        std::cout << "Thread №" << std::this_thread::get_id() << " get element №" << index << ": " << safetyVector[index] << std::endl;
        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        getElementTime.push_back(seconds);
        return safetyVector[index];
    } else {
        std::cout << "Thread try to get nonexistent element from vector" << std::endl;
    }
    return -1;
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
    clock_t start = clock();
    std::lock_guard<std::mutex> lock(locker);
    std::cout << "Thread №" << std::this_thread::get_id() << " push element: " << value << std::endl;
    safetyVector.push_back(value);
    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
    threadCount++;
    pushingTime.push_back(seconds);
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
