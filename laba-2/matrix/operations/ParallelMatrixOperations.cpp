//
// Created by 17491433 on 09.04.2020.
//

#include "ParallelMatrixOperations.h"
#include <omp.h>

std::vector<std::vector<int64_t>> ParallelMatrixOperations::transpositionMatrix(std::vector<std::vector<int64_t>> &a) {
    std::vector<std::vector<int64_t>> resultMatrix(a[0].size(), std::vector<int64_t>(a.size()));
    #pragma omp parallel for
    for (int64_t i = 0; i < a.size(); ++i) {
        #pragma omp parallel for
        for (int64_t j = 0; j < a[0].size(); ++j) {
            resultMatrix[j][i] = a[i][j];
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>>
ParallelMatrixOperations::sumMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a[0].size()));
    if(checkMatrix(a) && checkMatrix(b)) {
        #pragma omp parallel for num_threads(resultMatrix.size())
        for (int64_t i = 0; i < resultMatrix.size(); ++i) {
            #pragma omp parallel for num_threads(resultMatrix[0].size())
            for (int64_t j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = a[i][j] + b[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::subMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a[0].size()));
    if(checkMatrix(a) && checkMatrix(b)) {
        #pragma omp parallel for num_threads(resultMatrix.size())
        for (int64_t i = 0; i < resultMatrix.size(); ++i) {
            #pragma omp parallel for num_threads(resultMatrix[0].size())
            for (int64_t j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = a[i][j] - b[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::scalarMultMatrix(int64_t scalar, std::vector<std::vector<int64_t>> &a) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(a.size()));
    if(checkMatrix(a)) {
        #pragma omp parallel for num_threads(resultMatrix.size())
        for (int64_t i = 0; i < resultMatrix.size(); ++i) {
            #pragma omp parallel for num_threads(resultMatrix[0].size())
            for (int64_t j = 0; j < resultMatrix[0].size(); ++j) {
                resultMatrix[i][j] = scalar * a[i][j];
            }
        }
    }
    return resultMatrix;
}

std::vector<std::vector<int64_t>> ParallelMatrixOperations::multMatrix(std::vector<std::vector<int64_t>> &a, std::vector<std::vector<int64_t>> &b) {
    std::vector<std::vector<int64_t>> resultMatrix(a.size(), std::vector<int64_t>(b[0].size()));
    if(checkMatrixMultiplyAvailable(a, b)) {
        #pragma omp parallel for
        for (int64_t i = 0; i < a.size(); ++i) {
            #pragma omp parallel for
            for (int64_t j = 0; j < b[0].size(); ++j) {
                for (int64_t k = 0; k < b.size(); ++k) {
                    resultMatrix[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    return resultMatrix;
}

std::vector<int64_t> ParallelMatrixOperations::multMatrixVector(std::vector<std::vector<int64_t>> &a, std::vector<int64_t> &b) {
    std::vector <int64_t> resultVector(a.size());
    if(checkVectorMultiplyAvailable(a, b)) {
        #pragma omp parallel for
        for (int64_t i = 0; i < a.size(); ++i) {
            #pragma omp parallel for reduction(+:resultVector[i])
            for (int64_t j = 0; j < a[i].size(); ++j) {
                resultVector[i] += a[i][j] * b[j];
            }
        }
    }
    return resultVector;
}

int64_t ParallelMatrixOperations::frobeniusNorm(std::vector<std::vector<int64_t>> &a) {
    int64_t result(0);
    #pragma omp parallel for reduction(+:result)
    for (int i = 0; i < a.size(); ++i) {
        #pragma omp parallel for reduction(+:result)
        for (int j = 0; j < a[i].size(); ++j) {
            result+=pow(a[i][j], 2);
        }
    }
    return sqrt(result);
}

bool ParallelMatrixOperations::checkMatrix(std::vector<std::vector<int64_t>> &a) {
    return getSize() == a.size() && getSize() == a[0].size();
}

bool ParallelMatrixOperations::checkMatrixMultiplyAvailable(std::vector<std::vector<int64_t>> &matrixA, std::vector<std::vector<int64_t>> &matrixB) {
    return matrixA[0].size() == matrixB.size();
}

int64_t ParallelMatrixOperations::getSize() {
    return size;
}

bool ParallelMatrixOperations::checkVectorMultiplyAvailable(std::vector<std::vector<int64_t>> &matrixA, std::vector<int64_t> &vectorB) {
    return matrixA[0].size() == vectorB.size();
}

ParallelMatrixOperations::ParallelMatrixOperations(int64_t size): size(size) {

}

ParallelMatrixOperations::~ParallelMatrixOperations() {

}

void ParallelMatrixOperations::printMatrix(std::vector<std::vector<int64_t>> &a) {
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < a[i].size(); ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
