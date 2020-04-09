//
// Created by 17491433 on 08.04.2020.
//

#ifndef LAB2_PARALLELVECTOROPERATIONS_H
#define LAB2_PARALLELVECTOROPERATIONS_H

#include <vector>
#include <cmath>
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
};



#endif //LAB2_PARALLELVECTOROPERATIONS_H
