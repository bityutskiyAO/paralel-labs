#include <iostream>

#include <vector>
#include <cmath>
#include "SLAU.h"
#include "SlauGenerator.h"
#include "omp.h"
using namespace std;


int main() {
    double allTime(0);
    double allTimeParal(0);
//    for (int k = 0; k < 1000; ++k) {
//        SlauGenerator slauGenerator(50);
//        vector<vector<double>> matrix = slauGenerator.generateMatrix();
//        vector<double> x = slauGenerator.generateX();
//        vector<double> y = slauGenerator.getY(matrix, x);

//        cout << "SLAU answers" << endl;
//        for (int j = 0; j < x.size(); ++j) {
//            cout << "x[" << j << "] = " << x[j] << endl;
//        }

    vector<vector<double>> matrix = {
            {10, 1, -1},
            {1, 10, -1},
            {-1, 1, 10}
    };
    vector<double> y = {11, 10, 10};

        SLAU slau(matrix, y);

        double time1 = omp_get_wtime();
        vector<double> test = slau.gaus(3);
        double time2 = omp_get_wtime();
        allTime += time2 - time1;
        cout << "Gaus test" << endl;
        for (int i = 0; i < test.size(); ++i) {
            cout << "x[" << i << "] = " << test[i] << endl;
        }

        double timeParal1 = omp_get_wtime();
        vector<double> testParallel = slau.parallelGaus(3);
        double timeParal2 = omp_get_wtime();
        allTimeParal += timeParal2 - timeParal1;
        cout << "Parallel Gaus test" << endl;
        for (int i = 0; i < test.size(); ++i) {
            cout << "x[" << i << "] = " << test[i] << endl;
        }

//    cout << "Yacobi test" << endl;
//    vector<double> test2 = slau.yakobiGaus(50, y);
//    for (int i = 0; i < test2.size(); ++i) {
//        cout << "x[" << i << "] = " << test2[i]<< endl;
//    }
//
//    cout << "Zeidel test" << endl;
//    vector<double> test3 = slau.zeidel(50, y, 0.98);
//    for (int i = 0; i < test2.size(); ++i) {
//        cout << "x[" << i << "] = " << test2[i]<< endl;
//    }
//    }
    cout << "Straight time of 1000 iteration: " << allTime/1000 << endl;
    cout << "Parallel time of 1000 iteration: " << allTimeParal/1000 << endl;
    return 0;
}
