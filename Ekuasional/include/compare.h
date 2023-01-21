#ifndef COMPARE_H_
#define COMPARE_H_

const double TOLERANCE = 1e-12;

bool check_equal(const double equal1, const double equal2, const double tolerance = TOLERANCE);

bool check_greater(const double greater, const double lower, const double tolerance = TOLERANCE);

bool check_lower(const double lower, const double greater, const double tolerance = TOLERANCE);

#endif //COMPARE_H_
