#ifndef ODE_H
#define ODE_H

#include <vector>
#include <functional>

std::vector<std::vector<double>> pikar(const std::vector<std::function<double(const double, const std::vector<double>&)>>& f,const std::vector<double>& alpha,double t0,double tm,double step,bool isParallel);
double metric(const std::vector<double>& x, const std::vector<double>& y, bool is_parallel);
std::vector<double> calc(const std::function<double(const double)>& u, double t0, double tm, double step);
std::vector<std::vector<double>> transposition(const std::vector<std::vector<double>>& matrix);
double maxMetric(const std::vector<double>& x, const std::vector<double>& y);

#endif
