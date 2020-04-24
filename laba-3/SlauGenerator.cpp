//
// Created by 17491433 on 23.04.2020.
//

#include <iostream>
#include <random>
#include "SlauGenerator.h"

SlauGenerator::SlauGenerator(int n): n(n) {
    vector<vector<double>> matrix(n, vector<double>(n));
    vector<double> vec(n);
    A = matrix;
    x = vec;
}


vector<vector<double>> SlauGenerator::generateMatrix() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-10, 10);

    std::random_device rd2;
    std::mt19937 gen2(rd2());
    std::uniform_int_distribution<int> dis2(500, 550);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i == j) {
                A[i][i] = dis2(gen2);
            } else{
                A[i][j] = dis(gen);
            }
//            cout <<  A[i][j] << " ";
        }
//        cout << endl;
    }
    return A;
}

vector<double> SlauGenerator::generateX() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(-5, 5);
    for (int j = 0; j < n; ++j) {
        x[j] = dis(gen);
//        cout <<  x[j] << " ";
    }
//    cout << endl;
    return x;
}

vector<double> SlauGenerator::getY(vector<vector<double>> &matrix, vector<double> &x) {
    vector<double> y(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            y[i] += matrix[i][j]*x[j];
        }
//        cout <<  y[i] << " ";
    }
    return y;
}
