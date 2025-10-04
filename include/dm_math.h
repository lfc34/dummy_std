/* Reimplementation of C <math.h> */
#ifndef DM_MATH_H
#define DM_MATH_H

#define PI 3.14159265
#define EULER 2.71828
#define EPSILON 1e-9

// IEEE 754 standard
#define NAN_BITS 0x7FF8000000000000ULL
#define INF_BITS 0x7FF0000000000000ULL
#define NEG_INF_BITS 0xFFF0000000000000ULL
#define DM_NAN dm_nan()
#define DM_INFINITY dm_inf()

double factorial(int x);

// create a quiet nan
double dm_nan();

// create an inf
double dm_inf();

int dm_isnan(double x);
int dm_isinf(double x);

// return absolute value |x|
double dm_fabs(double x);

// returns non zero value if x is negative
int dm_signbit(double x);

// return exponential value of x
double dm_exp(double x);

// returns the larger from two values
double dm_fmax(double x, double y);

// return natural log of x
double dm_log(double x);

#endif