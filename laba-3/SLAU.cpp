//
// Created by 17491433 on 22.04.2020.
//

#include "SLAU.h"
#include <iostream>
#include <cmath>
#include "omp.h"

using namespace std;

SLAU::SLAU(vector<vector<double>> &matrix, vector<double> &y): matrix(matrix), y(y) {

}

vector<double> SLAU::gaus(int n) {
    vector<double> x(n);
    vector<vector<double>> matrix = getMatrix();
    vector<double> y = getVector();
    double max;
    int k, index;
    const double eps = 0.00001;  // точность
    k = 0;
    max = abs(matrix[k][k]);
    index = k;
    for (int i = k + 1; i < n; ++i) {
        if(abs(matrix[i][k]) > max) {
            max = abs(matrix[i][k]);
            index = i;
        }
    }
    if (max < eps){
        cout << "Решение получить невозможно из-за нулевого столбца ";
        cout << index << " матрицы A" << endl;
        return vector<double>(0);
    }
    while(k < n){
        //переставляем k строчку матрицы А со строчкой с наибольшим элементом
        for (int j = 0; j < n; j++)
        {
            double temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }
        //переставляем k строчку вектора решений со строчкой с наибольшим элементом
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;

        for (int i = k; i < n; i++){
            double tmp = matrix[i][k];
            if (abs(tmp) < eps) {
                continue; // для нулевого коэффициента пропустить
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] / tmp;
            }
            y[i] = y[i] / tmp;
            if (i == k) {
                continue; // уравнение не вычитать само из себя
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            }
            y[i] = y[i] - y[k];
        }
        k++;
    }
    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++) {
            y[i] = y[i] - matrix[i][k] * x[k];
        }
    }
    return x;
}

vector<double> SLAU::zeidel(int n, vector<double> x, double w) {
    double eps = 0.001;
    vector<double> tempX(n);
    vector<vector<double>> A = getMatrix();
    vector<double> f = getVector();
    double norm(0);
    int counter(0);// количество иттераций
    do {
        for (int i = 0; i < n; ++i) {
            tempX[i] = f[i];
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    tempX[i] -= A[i][j]*tempX[j];
                } else if ( j > i) {
                    tempX[i] -= A[i][j]*x[j];
                }
            }
            if(A[i][i] != 0) {
                tempX[i] = tempX[i] * w / A[i][i];
            }
            tempX[i] += (1 - w) * x[i];
        }
        norm = fabs(x[0] - tempX[0]);
        for (int h = 0; h < n; h++) {
            if (fabs(x[h] - tempX[h]) > norm)
                norm = fabs(x[h] - tempX[h]);
            x[h] = tempX[h];
        }
        counter +=1;
    } while (norm > eps);
    cout << "Zeidel method iteration count: " << counter << endl;
    return x;
}


vector<double> SLAU::yakobiGaus (int n, vector<double> x)
{
    double eps = 0.001;
    vector<double> tempX(n);
    vector<vector<double>> A = getMatrix();
    vector<double> f = getVector();
    double norm(0); // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
    int counter(0);// количество иттераций
    double max(0);
    for (int k = 0; k < n; ++k) {
        double test(0);
        for (int i = 0; i < n; ++i) {
            if(i != k && A[i][i] != 0) {
                test += abs(A[k][i]/A[i][i]);
            }
        }
        if(abs(test) > max) {
            max = test;
        }
    }
    if(max < 1) {
        do {
            for (int i = 0; i < n; i++) {
                tempX[i] = f[i];
                for (int j = 0; j < n; j++) {
                    if (i != j)
                        tempX[i] -= A[i][j] * x[j];
                }
                if (A[i][i] != 0) {
                    tempX[i] /= A[i][i];
                }
            }
            norm = fabs(x[0] - tempX[0]);
            for (int h = 0; h < n; h++) {
                if (fabs(x[h] - tempX[h]) > norm)
                    norm = fabs(x[h] - tempX[h]);
                x[h] = tempX[h];
            }
            counter += 1;
        } while (norm > eps);
        cout << "Yakobi method iteration count: " << counter << endl;
        return x;
    } else {
        cout << "Не выполнено необходимое условие" << endl;
        cout << "Norma B " << max << endl;
        return vector<double>(0);
    }
}


vector<vector<double>> SLAU::getMatrix() {
    return matrix;
}

SLAU::~SLAU() {

}

vector<double> SLAU::getVector() {
    return y;
}

vector<double> SLAU::parallelGaus(int n) {
    vector<double> x(n);
    vector<vector<double>> matrix = getMatrix();
    vector<double> y = getVector();
    double max;
    int k, index;
    const double eps = 0.00001;  // точность
    k = 0;
    max = abs(matrix[k][k]);
    index = k;
    for (int i = k + 1; i < n; ++i) {
        if(abs(matrix[i][k]) > max) {
            max = abs(matrix[i][k]);
            index = i;
        }
    }
    if (max < eps){
//            cout << "Решение получить невозможно из-за нулевого столбца ";
//            cout << index << " матрицы A" << endl;
        return vector<double>(0);
    }
    while(k < n){
        //переставляем k строчку матрицы А со строчкой с наибольшим элементом
        #pragma omp parallel for
        for (int j = 0; j < n; j++)
        {
            double temp = matrix[k][j];
            matrix[k][j] = matrix[index][j];
            matrix[index][j] = temp;
        }
        //переставляем k строчку вектора решений со строчкой с наибольшим элементом
        double temp = y[k];
        y[k] = y[index];
        y[index] = temp;
        #pragma omp parallel for
        for (int i = k; i < n; i++){
            double tmp = matrix[i][k];
            if (abs(tmp) < eps) {
                continue; // для нулевого коэффициента пропустить
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] / tmp;
            }
            y[i] = y[i] / tmp;
            if (i == k) {
                continue; // уравнение не вычитать само из себя
            }
            for (int j = 0; j < n; j++) {
                matrix[i][j] = matrix[i][j] - matrix[k][j];
            }
            y[i] = y[i] - y[k];
        }
        k++;
    }
    #pragma omp parallel for
    for (k = n - 1; k >= 0; k--) {
        x[k] = y[k];
        for (int i = 0; i < k; i++) {
            y[i] = y[i] - matrix[i][k] * x[k];
        }
    }
    return x;
}

vector<double> SLAU::parallelyakobiGaus(int n, vector<double> x) {
    double eps = 0.001;
    vector<double> tempX(n);
    vector<vector<double>> A = getMatrix();
    vector<double> f = getVector();
    double norm(0); // норма, определяемая как наибольшая разность компонент столбца иксов соседних итераций.
    int counter(0);// количество иттераций
    double max(0);
    for (int k = 0; k < n; ++k) {
        double test(0);
        #pragma omp parallel for reduction(+:test)
        for (int i = 0; i < n; ++i) {
            if(i != k && A[i][i] != 0) {
                test += abs(A[k][i]/A[i][i]);
            }
        }
        if(abs(test) > max) {
            max = test;
        }
    }
    if(max < 1) {
        do {
            #pragma omp parallel for
            for (int i = 0; i < n; i++) {
                tempX[i] = f[i];
                double tmp = tempX[i];
#pragma omp parallel for reduction(-:tmp)
                for (int j = 0; j < n; j++) {
                    if (i != j)
                        tmp -= A[i][j] * x[j];
                }
                if (A[i][i] != 0) {
                    tempX[i] /= A[i][i];
                }
            }
            norm = fabs(x[0] - tempX[0]);
            for (int h = 0; h < n; h++) {
                if (fabs(x[h] - tempX[h]) > norm)
                    norm = fabs(x[h] - tempX[h]);
                x[h] = tempX[h];
            }
            counter += 1;
        } while (norm > eps);
        cout << "Yakobi method iteration count: " << counter << endl;
        return x;
    } else {
        cout << "Не выполнено необходимое условие" << endl;
        cout << "Norma B " << max << endl;
        return vector<double>(0);
    }
}

vector<double> SLAU::parallelZeidel(int n, vector<double> x, double w) {
    double eps = 0.001;
    vector<double> tempX(n);
    vector<vector<double>> A = getMatrix();
    vector<double> f = getVector();
    double norm(0);
    int counter(0);// количество иттераций
    do {
        for (int i = 0; i < n; ++i) {
            tempX[i] = f[i];
            for (int j = 0; j < n; j++) {
                if (j < i) {
                    tempX[i] -= A[i][j]*tempX[j];
                } else if ( j > i) {
                    tempX[i] -= A[i][j]*x[j];
                }
            }
            if(A[i][i] != 0) {
                tempX[i] = tempX[i] * w / A[i][i];
            }
            tempX[i] += (1 - w) * x[i];
        }
        norm = fabs(x[0] - tempX[0]);
        for (int h = 0; h < n; h++) {
            if (fabs(x[h] - tempX[h]) > norm)
                norm = fabs(x[h] - tempX[h]);
            x[h] = tempX[h];
        }
        counter +=1;
    } while (norm > eps);
    cout << "Zeidel method iteration count: " << counter << endl;
    return x;
}
