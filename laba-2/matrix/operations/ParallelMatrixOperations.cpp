//
// Created by 17491433 on 09.04.2020.
//

#include "ParallelMatrixOperations.h"

std::vector<std::vector<int64_t>> ParallelMatrixOperations::transpositionMatrix(std::vector<std::vector<int64_t>> &a) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a.size()));
    for (int i = 0; i < resultMatrix.size(); ++i) {
        for (int j = 0; j < resultMatrix[0].size(); ++j) {
            resultMatrix[j][i] = a[i][j];
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>>
ParallelMatrixOperations::sumMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a.size()));
    if(checkMatrix(a) && checkMatrix(b)) {
        for (int i = 0; i < resultMatrix.size(); ++i) {
            for (int j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = a[i][j] + b[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::subMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a.size()));
    if(checkMatrix(a) && checkMatrix(b)) {
        for (int i = 0; i < resultMatrix.size(); ++i) {
            for (int j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::scalarMultMatrix(int64_t scalar, std::vector<std::vector<int64_t>> &a) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a.size()));
    if(checkMatrix(a)) {
        for (int i = 0; i < resultMatrix.size(); ++i) {
            for (int j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = scalar * a[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::multMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    return std::vector<std::vector<int64_t>>();
}

std::vector<int64_t> ParallelMatrixOperations::multMatrixVector(std::vector<std::vector<int64_t>> &a, std::vector<int64_t> &b) {
    return std::vector<int64_t>();
}

int64_t ParallelMatrixOperations::frobeniusNorm(std::vector<int64_t> &a) {
    return 0;
}

bool ParallelMatrixOperations::checkMatrix(std::vector<std::vector<int64_t>> &a) {
    return getSize() == a.size() && getSize() == a[0].size();
}

bool ParallelMatrixOperations::checkMatrixMultiplyAvailable(std::vector<std::vector<int64_t>> &matrixA,
                                                            std::vector<std::vector<int64_t>> &matrixB) {
    return matrixA[0].size() == matrixB.size();
}

int64_t ParallelMatrixOperations::getSize() {
    return size;
}

bool ParallelMatrixOperations::checkVectorMultiplyAvailable(std::vector<std::vector<int64_t>> &matrixA,
                                                            std::vector<int64_t> &vectorB) {
    return matrixA[0].size() == vectorB.size();
}

ParallelMatrixOperations::ParallelMatrixOperations(int64_t size): size(size) {

}

ParallelMatrixOperations::~ParallelMatrixOperations() {

}
