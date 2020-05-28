//
// Created by 17491433 on 27.05.2020.
//

#ifndef LABA5_THREADSAVEVECTOR_H
#define LABA5_THREADSAVEVECTOR_H

#include <vector>
#include <thread>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

class ThreadSaveVector {
    private:
        std::vector<int> safetyVector;
        std::mutex locker;

    public:
        explicit ThreadSaveVector();
        void savePushBack (int value);
        std::thread pushThread(int value);
        void savePopBack ();
        std::thread popThread();
        int saveGetElement (int index);
        std::thread getElementThread(int index);
        void printVector();
        std::vector<int> getVector();

        std::vector<double> pushingTime;
        std::vector<double> popingTime;
        std::vector<double> getElementTime;
        int threadCount;
};


#endif //LABA5_THREADSAVEVECTOR_H
