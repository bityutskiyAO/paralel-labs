//
// Created by 17491433 on 08.04.2020.
//

#ifndef LAB2_PARALLELVECTOROPERATIONS_H
#define LAB2_PARALLELVECTOROPERATIONS_H

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

class ParallelVectorOperations {
    private:
        int64_t size;
    public:
    ParallelVectorOperations(int64_t size);
    ~ParallelVectorOperations();
    int64_t getSize();
    bool checkVector(std::vector<int64_t>& a);
    std::vector<int64_t > vectorSum(std::vector<int64_t>& a, std::vector<int64_t>& b);
    std::vector<int64_t> vectorSub(std::vector<int64_t>& a, std::vector<int64_t>& b);
    int64_t vectorScalarMult(std::vector<int64_t>& a, std::vector<int64_t>& b);
    std::vector<int64_t> vectorConstantMult(int64_t scalar, std::vector<int64_t>& b);
    double getVectorLength(std::vector<int64_t>& b);
    void printVector(std::vector<int64_t> &a);
};
//std::ostream& operator << (std::ostream &os,const std::vector<int64_t> &a) {
//    for (int i = 0; i < a.size(); ++i) {
//        os << a[i] << " ";
//    }
//    os << std::endl;
//    return os;
//}



#endif //LAB2_PARALLELVECTOROPERATIONS_H
