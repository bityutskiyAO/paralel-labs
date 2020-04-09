#include <iostream>
#include <vector>
#include <algorithm>
#include "matrix/operations/ParallelMatrixOperations.h"

using namespace std;

int main() {
    int64_t size(0);
    ParallelMatrixOperations operations(2);
    vector<vector<int64_t>> matrix = {{1, 4}, {2, 3}};
    vector<vector<int64_t>> result = operations.transpositionMatrix(matrix);
    cout << result;
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[0].size(); ++j) {
//            cout << result[i][j] << " ";
//        }
//        cout << endl;
//    }

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
