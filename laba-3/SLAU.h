//
// Created by 17491433 on 22.04.2020.
//

#ifndef LABA_3_SLAU_H
#define LABA_3_SLAU_H

#include <vector>
#include <cmath>

using namespace std;

class SLAU {
private:
    vector<vector<double>> matrix;
    vector<double> y;
public:
    SLAU(vector<vector<double>>& matrix, vector<double> &y);
    ~SLAU();
    vector<vector<double>> getMatrix();
    vector<double> getVector();
    vector<double> gaus(int n);
    vector<double> yakobiGaus(int n, vector<double> x);
    vector<double> zeidel(int n, vector<double> x, double w);
};


#endif //LABA_3_SLAU_H
