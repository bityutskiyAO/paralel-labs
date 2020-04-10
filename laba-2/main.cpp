#include <iostream>
#include <vector>
#include "matrix/operations/ParallelMatrixOperations.h"
#include "vector/operations/ParallelVectorOperations.h"

using namespace std;

int main() {
    int64_t size(2);
    ParallelMatrixOperations matrixOperations(size);
    vector<vector<int64_t>> matrix1 = {{1, 4}, {2, 3}};
    vector<vector<int64_t>> matrix2 = {{1, 4}, {2, 3}};
    vector<vector<int64_t>> resultMatrix = matrixOperations.transpositionMatrix(matrix1);
    vector<vector<int64_t>> resultMatrix2 = matrixOperations.sumMatrix(matrix1, matrix2);
    matrixOperations.printMatrix(resultMatrix2);

    /* ------------------------------------------------------------------*/
//    vector<int64_t> vec1 = {2, 4, 3, 2, 2};
//    vector<int64_t> vec2 = {8, 6, 1, 1, 1};
//    ParallelVectorOperations vectorOperations(size);
//    vector<int64_t> resultVector = vectorOperations.vectorSum(vec1, vec2);
//    vectorOperations.printVector(resultVector);


//    cout << "Введите длину вектора: " << endl;
//    cin >> size;
//    vector<int64_t> vectorA(size);
//    vector<int64_t> vectorB(size);
//    cout << "Введите координаты 1 вектора: " << endl;
//    for (int64_t i = 0; i < size; ++i) {
//        cin >> vectorA[i];
//    }
//    cout << "Введите координаты 2 вектора: " << endl;
//    for (int64_t j = 0; j < size; ++j) {
//        cin >> vectorB[j];
//    }
//
//    for (int64_t k = 0; k < size; ++k) {
//        cout << vectorA[k] << " " ;
//    }
//    cout <<endl;
//    for (int64_t k = 0; k < size; ++k) {
//        cout << vectorB[k] << " " ;
//    }
    return 0;
}
