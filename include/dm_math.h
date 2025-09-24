/* Reimplementation of C <math.h> */
#ifndef DM_MATH_H
#define DM_MATH_H

#define PI 3.14159265
#define EULER 2.71828
#define EPSILON 1e-9

// IEEE 754 standard
#define NAN 0x7FF8000000000000ULL
#define INF 0x7FF000000000000ULL
#define NEG_INF 0xFFF0000000000000ULL

double factorial(int x);

// create a quiet nan
double dm_gen_quiet_nan();

// create an inf
double dm_gen_inf(int sign);

// return absolute value |x|
double dm_fabs(double x);

// returns non zero value if x is negative
int dm_signbit(double x);

// return exponential value of x
double dm_exp(double x);

// return natural log of x
double dm_log(double x);

#endif