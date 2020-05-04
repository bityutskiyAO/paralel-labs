#include <cstdint>
#include <cstddef>
#include <cmath>
#include <omp.h>

#include "ODU.h"

using namespace std;

vector<vector<double>> pikar(const vector<function<double(const double, const vector<double> &)>> &f, const vector<double> &alpha,
      const double t0, const double tm, const double step, const bool isParallel) {

    // Количество потоков
    const int32_t threadsNumber(isParallel ? omp_get_num_procs() : 1);

    // Значения переменной t на отрезке [t0; tm] c шагом step
    vector<double> t;
    double currentT(t0);
    while (currentT < tm) {
        t.push_back(currentT);
        currentT += step;
    }
    t.push_back(tm);

    const int32_t pointsAmount(t.size());
    // количество точек в каждой нити, кроме последней
    const int32_t nPoints(pointsAmount / threadsNumber);
    const int32_t uSize(f.size());

    vector<vector<double>> integralsCalculation(pointsAmount - 1, vector<double>(uSize));
    //(u[i][j] - значение функции u[j] в точке t[i])
    vector<vector<double>> u(pointsAmount, alpha);
    vector<vector<double>> previousU(pointsAmount);

    const double epsilon(0.000001);
    bool condition(true);

    //суммы значения интеграллов в каждой нити для каждой функции u
    vector<vector<double>> sum(threadsNumber, vector<double>(uSize));

    #pragma omp parallel num_threads(threadsNumber)
    {
        while (condition) {
            // Сохранить найденные значения u
            #pragma omp single nowait
            {
                previousU = u;
            }

            // Номер нити
            int32_t thread(omp_get_thread_num());
            // Номер первого значения перменной t в нити
            int32_t start(thread * nPoints);
            // Номер последнего значения перменной t в нити
            int32_t end(start + nPoints - 1);
            // В последней нити нужно учесть pointsAmount % threadsNumber
            if (thread == (threadsNumber - 1)) {
                end = t.size() - 2;
            }
            // Обнулим значения сумм
            for (ptrdiff_t i(0); i < uSize; i += 1) {
                sum[thread][i] = 0.0;
            }

            // вычисление значений интегралов
            for (ptrdiff_t m(start); m <= end; m += 1) {
                double delta_t(t[m + 1] - t[m]);
                for (ptrdiff_t i(0); i < uSize; i += 1) {
                    integralsCalculation[m][i] = delta_t * (f[i](t[m], u[m]) + f[i](t[m + 1], u[m + 1])) / 2;
                    sum[thread][i] += integralsCalculation[m][i];
                }
            }

            // Изменение номера последнего значения t
            if (thread < (threadsNumber - 1)) {
                end = start + nPoints - 2;
            }

            // Ожидание завершения вычисления значений интегралов во всех нитях
#pragma omp barrier

            // Вычисление начальных значений u[start]
            for (ptrdiff_t i(0); i < uSize; i += 1) {
                u[start][i] = u[0][i];
                for (ptrdiff_t j(0); j < thread; j += 1) {
                    u[start][i] += sum[j][i];
                }
            }
            // Обновление значений искомых функций при всех значениях аргумента t
            for (ptrdiff_t m(start); m <= end; m += 1) {
                for (ptrdiff_t i(0); i < uSize; i += 1) {
                    u[m + 1][i] = u[m][i] + integralsCalculation[m][i];
                }
            }

            // проверка условия выхода из цикла
            #pragma omp single
            {
                ptrdiff_t m(0);
                double diff(metric(u[m], previousU[m], isParallel));
                while (((diff < epsilon) && (m + 1) < pointsAmount)) {
                    m += 1;
                    diff = metric(u[m], previousU[m], isParallel);
                }
                condition = diff >= epsilon;
            }

            // Ожидание завершения вычислений во всех нитях
        #pragma omp barrier
        }
    }
    return u;
}

double metric(const vector<double> &x, const vector<double> &y, const bool isParallel) {
    double res(0.0);
    size_t n(x.size());
    // Найдём в параллельном или последовательном режиме значение суммы
        #pragma omp parallel for reduction(+:res) if (isParallel)
    for (ptrdiff_t i = 0; i < n; i += 1) {
        res += pow(x[i] - y[i], 2);
    }
    return sqrt(res);
}

vector<double> calc(const function<double(const double)> &u,double t0,double tm,double step) {
    vector<double> ans;
    double curr_t(t0);
    while (curr_t < tm) {
        ans.push_back(u(curr_t));
        curr_t += step;
    }
    ans.push_back(u(tm));
    return ans;
}


vector<vector<double>> transposition(const vector<vector<double>> &matrix) {
    int32_t n(matrix.size());
    int32_t m(matrix[0].size());
    vector<vector<double>> res(m);
    for (ptrdiff_t i(0); i < m; i += 1) {
        res[i].resize(n, 0.0);
        for (ptrdiff_t j(0); j < n; j += 1) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}


double maxMetric(const vector<double> &x, const vector<double> &y) {
    double max(abs(x[0] - y[0]));
    double v(0.0);
    size_t n(x.size());

    for (ptrdiff_t i(1); i < n; i += 1) {
        v = abs(x[i] - y[i]);
        if (v > max) {
            max = v;
        }
    }

    return max;
}
