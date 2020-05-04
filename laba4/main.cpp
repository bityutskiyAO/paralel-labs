#include <iostream>
#include <omp.h>
#include <cmath>
#include "ODU.h"

double u1(const double t) {
  return t + 2 * t + 1;
}
double u2(const double t) {
  return t;
}
double u3(const double t) {
  return log(t) + t;
}
double u4(const double t) {
  return -sin(t);
}
double u5(const double t) {
  return cos(t);
}

double f1(const double t, const std::vector<double>& u) {
  return u[1];
}
double f2(const double t, const std::vector<double>& u) {
  return u[3] + u[4] * u[2];
}
double f3(const double t, const std::vector<double>& u) {
  return 1 / u[1] + t;
}
double f4(const double t, const std::vector<double>& u) {
  return u[4];
}
double f5(const double t, const std::vector<double>& u) {
  return -u[3] + u[2];
}



int main() {
  using namespace std;

  vector<function<double(const double, const vector<double>&)>> f{ f1, f2, f3, f4, f5 };
  double t0(0.1);
  double tm(10.1);
  vector<double> alpha{ u1(t0), u2(t0), u3(t0), u4(t0), u5(t0) };
  double step(0.001);

  // Найдём значение коэффициента ускорения
  double time_sequental(0.0);
  double time_parallel(0.0);
  double start(0.0);
  for (ptrdiff_t i(0); i < 5; i += 1) {
    start = omp_get_wtime();
      pikar(f, alpha, t0, tm, step, false);
    time_sequental += omp_get_wtime() - start;

    start = omp_get_wtime();
      pikar(f, alpha, t0, tm, step, true);
    time_parallel += omp_get_wtime() - start;
  }
  cout << "coef: " << time_sequental / time_parallel << endl;

  char stop('0');
  cin >> stop;
  return 0;
}
