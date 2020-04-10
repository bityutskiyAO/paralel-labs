#include <iostream>
#include <vector>
#include "matrix/operations/ParallelMatrixOperations.h"
#include "vector/operations/ParallelVectorOperations.h"

using namespace std;

int main() {
    int64_t size(2);
    ParallelMatrixOperations matrixOperations(size);
    ParallelVectorOperations vectorOperations(size);
    vector<vector<int64_t>> matrix1 = {{1, 4}, {2, 3}};
    vector<vector<int64_t>> matrix2 = {{1, 4}, {2, 3}};
    vector<int64_t> vec1 = {2, 4};
    vector<int64_t> vec2 = {4, 2};

    vector<vector<int64_t>> resultMatrix = matrixOperations.transpositionMatrix(matrix1);
    cout << "Транпонировании матрицы" << endl;
    matrixOperations.printMatrix(resultMatrix);
    resultMatrix = matrixOperations.sumMatrix(matrix1, matrix2);
    cout << "Сложение матриц" << endl;
    matrixOperations.printMatrix(resultMatrix);
    resultMatrix = matrixOperations.subMatrix(matrix1, matrix2);
    cout << "Вычитание матриц" << endl;
    matrixOperations.printMatrix(resultMatrix);
    resultMatrix = matrixOperations.multMatrix(matrix1, matrix2);
    cout << "Перемножение матриц" << endl;
    matrixOperations.printMatrix(resultMatrix);
    vector<int64_t> resultVector = matrixOperations.multMatrixVector(matrix1, vec1);
    cout << "Умножение матрицы на вектор" << endl;
    vectorOperations.printVector(resultVector);
    int64_t result = matrixOperations.frobeniusNorm(matrix1);
    cout << "Метрика Фробениуса" << endl;
    cout << result << endl;
    resultMatrix = matrixOperations.scalarMultMatrix(5, matrix2);
    cout << "Умножение на скаляр" << endl;
    matrixOperations.printMatrix(resultMatrix);
    cout << endl;
    vector<int64_t> resultVector2 = vectorOperations.vectorSum(vec1, vec2);
    cout << "Сложение векторов" << endl;
    vectorOperations.printVector(resultVector2);
    resultVector2= vectorOperations.vectorSub(vec1, vec2);
    cout << "Разность векторов" << endl;
    vectorOperations.printVector(resultVector2);
    int64_t result2 = vectorOperations.vectorScalarMult(vec1, vec2);
    cout << "Скалярное произведение" << endl;
    cout << result2 << endl;
    double result3 = vectorOperations.getVectorLength(vec1);
    cout << "Длина вектора" << endl;
    cout << result3 << endl;
    resultVector2 = vectorOperations.vectorConstantMult(5, vec2);
    cout << "Умножение на скаляр" << endl;
    vectorOperations.printVector(resultVector2);

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
