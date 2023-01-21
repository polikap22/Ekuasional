//Didapatkan dari stackoverflow :v
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
    ONE_RT  =  1, /// One root
    TWO_RT  =  2, /// Two roots
    ZERO_RT =  0, /// Zero roots
    INF_RT  = -1, /// Infinity roots
    ERR_INF = -2, /// At least one of the roots is infinite 
};

roots_state solve_quadratic(const square_params coeffs, square_solutions *solutions);

roots_state solve_linear(const double b, const double c, double *solution);

double calc_discr(const square_params coeffs); 


#endif //SOLVE_H_
