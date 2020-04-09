//
// Created by 17491433 on 08.04.2020.
//

#include "ParallelVectorOperations.h"

ParallelVectorOperations::ParallelVectorOperations(int64_t size): size(size) {

}

ParallelVectorOperations::~ParallelVectorOperations() {

}

std::vector<int64_t> ParallelVectorOperations::vectorSum(std::vector<int64_t> &a, std::vector<int64_t> &b) {
    std::vector<int64_t> resultVector(getSize(), 0);
    if(checkVector(a) && checkVector(b)) {
        for (int i = 0; i < resultVector.size(); ++i) {
            resultVector[i] = a[i] + b[i];
        }
    }
    return resultVector;
}

std::vector<int64_t> ParallelVectorOperations::vectorSub(std::vector<int64_t> &a, std::vector<int64_t> &b) {
    std::vector<int64_t> resultVector(getSize(), 0);
    if(checkVector(a) && checkVector(b)) {
        for (int i = 0; i < resultVector.size(); ++i) {
            resultVector[i] = a[i] - b[i];
        }
    }
    return resultVector;
}

int64_t ParallelVectorOperations::vectorScalarMult(std::vector<int64_t> &a, std::vector<int64_t> &b) {
    int64_t result(0);
    if(checkVector(a) && checkVector(b)) {
        for (int i = 0; i < getSize(); ++i) {
            result += a[i] * b[i];
        }
    }
    return result;
}

std::vector<int64_t> ParallelVectorOperations::vectorConstantMult(int64_t scalar, std::vector<int64_t> &b) {
    std::vector<int64_t> resultVector(getSize(), 0);
    if(checkVector(b)) {
        for (int i = 0; i < resultVector.size(); ++i) {
            resultVector[i] = scalar * b[i];
        }
    }
    return resultVector;
}

double ParallelVectorOperations::getVectorLength(std::vector<int64_t> &b) {
    double result(0);
    if(checkVector(b)) {
        for (int i = 0; i < b.size(); ++i) {
            result += pow(b[i],2);
        }
        result = sqrt(result);
    }
    return result;
}

int64_t ParallelVectorOperations::getSize() {
    return size;
}

bool ParallelVectorOperations::checkVector(std::vector<int64_t> &a) {
    return a.size() == getSize();
}

std::ostream& operator << (std::ostream &os, std::vector<int64_t> &a) {
    for (int i = 0; i < a.size(); ++i) {
        os << a[i] << " ";
    }
    os << endl;
    return os;
}