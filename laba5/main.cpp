
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <thread>
#include <time.h>
#include <stdio.h>
#include "ThreadSaveQueue.h"
#include "ThreadSaveStack.h"
#include "ThreadSaveVector.h"


void testVectorPush(ThreadSaveVector * testVector) {
    clock_t start = clock();

    std::thread thread = testVector->pushThread(1);
    std::thread thread1 = testVector->pushThread(2);
    std::thread thread2 = testVector->pushThread(3);
    std::thread thread3 = testVector->pushThread(4);
    std::thread thread4 = testVector->pushThread(5);

    thread.join();
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();

    clock_t end = clock();
    double seconds = (double)(end - start) / CLOCKS_PER_SEC;
//    printf("The time: %f seconds\n", seconds);
    testVector->printVector();
}

void testVectorPop(ThreadSaveVector * testVector) {
    std::thread popThread = testVector->popThread();
    std::thread popThread1 = testVector->popThread();
    std::thread popThread2 = testVector->popThread();
    std::thread popThread3 = testVector->popThread();
    std::thread popThread4 = testVector->popThread();

    popThread.join();
    popThread1.join();
    popThread2.join();
    popThread3.join();
    popThread4.join();
}

void testVectorGetElement(ThreadSaveVector * testVector) {
    std::thread getThread = testVector->getElementThread(10);
    std::thread getThread1 = testVector->getElementThread(1);
    std::thread getThread2 = testVector->getElementThread(2);
    std::thread getThread3 = testVector->getElementThread(0);
    std::thread getThread4 = testVector->getElementThread(5);

    getThread.join();
    getThread1.join();
    getThread2.join();
    getThread3.join();
    getThread4.join();
}

void testStackPush(ThreadSaveStack * testStack) {
    std::thread pushThread = testStack->pushThread(10);
    std::thread pushThread1 = testStack->pushThread(1);
    std::thread pushThread2 = testStack->pushThread(2);
    std::thread pushThread3 = testStack->pushThread(0);
    std::thread pushThread4 = testStack->pushThread(5);

    pushThread.join();
    pushThread1.join();
    pushThread2.join();
    pushThread3.join();
    pushThread4.join();
}
void testStackPop(ThreadSaveStack * testStack) {
    std::thread popThread = testStack->popThread();
    std::thread popThread1 = testStack->popThread();
    std::thread popThread2 = testStack->popThread();
    std::thread popThread3 = testStack->popThread();
    std::thread popThread4 = testStack->popThread();

    popThread.join();
    popThread1.join();
    popThread2.join();
    popThread3.join();
    popThread4.join();
}

void testStackTop(ThreadSaveStack * testStack) {
    std::thread topThread = testStack->topThread();
    std::thread topThread1 = testStack->topThread();
    std::thread topThread2 = testStack->topThread();
    std::thread topThread3 = testStack->topThread();
    std::thread topThread4 = testStack->topThread();

    topThread.join();
    topThread1.join();
    topThread2.join();
    topThread3.join();
    topThread4.join();
}


void testQueuePush(ThreadSaveQueue * testQueue) {
    std::thread pushThread = testQueue->pushThread(10);
    std::thread pushThread1 = testQueue->pushThread(1);
    std::thread pushThread2 = testQueue->pushThread(2);
    std::thread pushThread3 = testQueue->pushThread(0);
    std::thread pushThread4 = testQueue->pushThread(5);

    pushThread.join();
    pushThread1.join();
    pushThread2.join();
    pushThread3.join();
    pushThread4.join();
}
void testQueuePop(ThreadSaveQueue * testQueue) {
    std::thread popThread = testQueue->popThread();
    std::thread popThread1 = testQueue->popThread();
    std::thread popThread2 = testQueue->popThread();
    std::thread popThread3 = testQueue->popThread();
    std::thread popThread4 = testQueue->popThread();

    popThread.join();
    popThread1.join();
    popThread2.join();
    popThread3.join();
    popThread4.join();
}

void testQueueTop(ThreadSaveQueue * testQueue) {
    std::thread topThread = testQueue->topThread();
    std::thread topThread1 = testQueue->topThread();
    std::thread topThread2 = testQueue->topThread();
    std::thread topThread3 = testQueue->topThread();
    std::thread topThread4 = testQueue->topThread();

    topThread.join();
    topThread1.join();
    topThread2.join();
    topThread3.join();
    topThread4.join();
}



int main() {
    auto* testVector = new ThreadSaveVector();
    auto* testStack = new ThreadSaveStack();
    auto* testQueue = new ThreadSaveQueue();

    testQueuePush(testQueue);
    testQueueTop(testQueue);
    testQueuePop(testQueue);

    testStackPush(testStack);
    testStackTop(testStack);
    testStackPop(testStack);

    testVectorPush(testVector);
    testVectorGetElement(testVector);
    testVectorPop(testVector);
    return 0;
}
