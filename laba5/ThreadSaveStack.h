//
// Created by 17491433 on 27.05.2020.
//

#ifndef LABA5_THREADSAVESTACK_H
#define LABA5_THREADSAVESTACK_H

#include <stack>
#include <thread>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

class ThreadSaveStack {
private:
    std::stack<int, std::vector<int>> safetyStack;
    std::mutex locker;
public:
    explicit ThreadSaveStack();
    void savePush (int value);
    std::thread pushThread(int value);
    void savePop ();
    std::thread popThread();
    int saveTop ();
    std::thread topThread();
    std::stack<int, std::vector<int>> getStack();
};


#endif //LABA5_THREADSAVESTACK_H
