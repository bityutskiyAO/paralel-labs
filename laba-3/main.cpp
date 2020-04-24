#include <iostream>

#include <vector>
#include <cmath>
#include "SLAU.h"
#include "SlauGenerator.h"

using namespace std;

int main() {
    SlauGenerator slauGenerator(50);
    vector<vector<double>> matrix = slauGenerator.generateMatrix();
    vector<double> x = slauGenerator.generateX();
    vector<double> y = slauGenerator.getY(matrix, x);

    cout << "SLAU answers" << endl;
    for (int j = 0; j < x.size(); ++j) {
        cout << "x[" << j <<"] = " << x[j] << endl;
    }

//    vector<vector<double>> matrix = {
//            {10, 1, -1},
//            {1, 10, -1},
//            {-1, 1, 10}
//    };
//    vector<double> y = {11, 10, 10};

    SLAU slau(matrix, y);

    vector<double> test = slau.gaus(50);
    cout << "Gaus test" << endl;
    for (int i = 0; i < test.size(); ++i) {
        cout << "x[" << i << "] = " << test[i]<< endl;
    }
    cout << "Yacobi test" << endl;
    vector<double> test2 = slau.yakobiGaus(50, y);
    for (int i = 0; i < test2.size(); ++i) {
        cout << "x[" << i << "] = " << test2[i]<< endl;
    }

    cout << "Zeidel test" << endl;
    vector<double> test3 = slau.zeidel(50, y, 0.98);
    for (int i = 0; i < test2.size(); ++i) {
        cout << "x[" << i << "] = " << test2[i]<< endl;
    }

    return 0;
}
