//
// Created by 17491433 on 04.05.2020.
//

#ifndef LABA4_ODU_H
#define LABA4_ODU_H

#include <vector>
#include <cmath>

using namespace std;

class ODU {
    private:
        int size;
    public:
        ODU(int size);
        ~ODU();
        int getSize();
        vector<vector<double>> pikar(const std::vector<std::function<double(const double, const std::vector<double>&)>>& f,
                             const std::vector<double>& alpha,
                             const double t0,
                             const double tm,
                             const double step,
                             const bool is_parallel);
    // Функция для получения значений функции u на отрезке [t0; tm]
        std::vector<double> calculate(
                const std::function<double(const double)>& u,
                const double t0,
                const double tm,
                const double step);

    // Реализация операции транспонирования
        std::vector<std::vector<double>> transpose(const std::vector<std::vector<double>>& matrix);

    // Реализация метрики, основанной на макимум-норме
        double maximumMetric(const std::vector<double>& x, const std::vector<double>& y);
};


#endif //LABA4_ODU_H
