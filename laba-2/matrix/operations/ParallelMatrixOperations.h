//
// Created by 17491433 on 09.04.2020.
//

#ifndef LAB2_PARALLELMATRIXOPERATIONS_H
#define LAB2_PARALLELMATRIXOPERATIONS_H

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

class ParallelMatrixOperations {
    private:
        int64_t size;
    public:
        ParallelMatrixOperations(int64_t size);
        ~ParallelMatrixOperations();
        std::vector<std::vector<int64_t>> transpositionMatrix(std::vector<std::vector<int64_t>>& a);
        std::vector<std::vector<int64_t>> sumMatrix(std::vector<std::vector<int64_t>>& a, std::vector<std::vector<int64_t>>& b);
        std::vector<std::vector<int64_t>> subMatrix(std::vector<std::vector<int64_t>>& a, std::vector<std::vector<int64_t>>& b);
        std::vector<std::vector<int64_t>> scalarMultMatrix(int64_t scalar, std::vector<std::vector<int64_t>>& b);
        std::vector<std::vector<int64_t>> multMatrix(std::vector<std::vector<int64_t>>& a, std::vector<std::vector<int64_t>>& b);
        std::vector<int64_t> multMatrixVector(std::vector<std::vector<int64_t>>& a, std::vector<int64_t>& b);
        int64_t frobeniusNorm(std::vector<std::vector<int64_t>>& a);
        bool checkMatrix(std::vector<std::vector<int64_t>>& a);
        bool checkMatrixMultiplyAvailable(std::vector<std::vector<int64_t>>& matrixA, std::vector<std::vector<int64_t>> &matrixB);
        bool checkVectorMultiplyAvailable(std::vector<std::vector<int64_t>>& matrixA, std::vector<int64_t>& vectorB);
        int64_t getSize();
        void printMatrix(std::vector<std::vector<int64_t>> &a);
};
//std::ostream& operator << (std::ostream &os, std::vector<std::vector<int64_t>> &a) {
//    for (int i = 0; i < a.size(); ++i) {
//        for (int j = 0; j < a[i].size(); ++j) {
//            os << a[i][j] << " ";
//        }
//        os << std::endl;
//    }
//    os << std::endl;
//    return os;
//}

#endif //LAB2_PARALLELMATRIXOPERATIONS_H
