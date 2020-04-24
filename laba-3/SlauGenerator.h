//
// Created by 17491433 on 23.04.2020.
//

#ifndef LABA_3_SLAUGENERATOR_H
#define LABA_3_SLAUGENERATOR_H

#include <vector>
#include <cmath>

using namespace std;

class SlauGenerator {
    private:
        int n;
        vector<vector<double>> A;
        vector<double> x;
    public:
        explicit SlauGenerator(int n);
        vector<double> getY(vector<vector<double>> &matrix, vector<double> &x);
        vector<vector<double>> generateMatrix();
        vector<double> generateX();
};


#endif //LABA_3_SLAUGENERATOR_H
