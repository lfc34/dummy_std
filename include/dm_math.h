/* Reimplementation of C <math.h> */
#ifndef DM_MATH_H
#define DM_MATH_H

#define PI 3.14159265
#define EULER 2.71828
#define EPSILON 1e-9

// create a quiet nan
double dm_gen_quiet_nan();

// create an inf
double dm_gen_inf(int sign);

// return absolute value |x|
double dm_fabs(double x);

// return natural log of x
double dm_log(double x);

#endif