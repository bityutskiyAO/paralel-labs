//
// Created by 17491433 on 27.05.2020.
//

#ifndef LABA5_THREADSAVEQUEUE_H
#define LABA5_THREADSAVEQUEUE_H

#include <queue>
#include <thread>
#include <cmath>
#include <iostream>
#include <algorithm>

class ThreadSaveQueue {
private:
    std::queue<int> safetyQueue;
    std::mutex locker;
public:
    ThreadSaveQueue();
    void savePushBack (int value);
    std::thread pushThread(int value);
    void savePopBack ();
    std::thread popThread();
    int saveTop ();
    std::thread topThread();
    std::queue<int> getQueue();
};


#endif //LABA5_THREADSAVEQUEUE_H
