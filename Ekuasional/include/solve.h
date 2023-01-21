#ifndef SOLVE_H_
#define SOLVE_H_

struct square_params {
    double a;
    double b;
    double c;
};

struct square_solutions {
    double x1;
    double x2;
};

enum roots_state {
    ONE_RT  =  1, /// 1 Akar
    TWO_RT  =  2, /// 2 Akar
    ZERO_RT =  0, /// Null
    INF_RT  = -1, /// Akar Inf
    ERR_INF = -2, /// Setidaknya 1 akar inf
};

roots_state solve_quadratic(const square_params coeffs, square_solutions *solutions);

roots_state solve_linear(const double b, const double c, double *solution);

double calc_discr(const square_params coeffs); 


#endif //SOLVE_H_
