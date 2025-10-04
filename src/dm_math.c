#include "dm_math.h"
#include "dm_string.h"
#include <stdio.h>

// TODO: add checks for nan, -inf and +inf in each func

// pow used ONLY for positive natural numbers
static double natural_pow(double base, int exp) {
    if (exp == 0) {
        return 1;
    }
    if (base == 0 || (base > 0 && base < EPSILON)) {
        return 0;
    }
    double res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

double factorial(int x) {
    if (x == 0 || x == 1 || (x > 0 && x < EPSILON)) {
        return 1;
    }
    if (x < 0) {
        return dm_nan();
    }
    double res = 1.0f;
    for (int i = 1; i <= x; i++) {
        res *= i;
    }
    return res;
}

double dm_nan() {
    unsigned long long bits = NAN_BITS;
    double nan_val;
    dm_memcpy(&nan_val, &bits, sizeof(nan_val));
    return nan_val;
}

double dm_inf() {
    unsigned long long bits = INF_BITS;
    double inf;
    dm_memcpy(&inf, &bits, sizeof(inf));
    return inf;
}

int dm_isnan(double x) {
    const double nan = dm_nan();
    return (dm_memcmp((void*) &x, (void*)&nan, sizeof(double)));
}
int dm_isinf(double x) {
    printf("dm_isinf: x = %lf\n", x);
    if (x == DM_INFINITY) return 1;
    else if (x == -DM_INFINITY) return -1;
    else return 0;
}

double dm_fabs(double x) {
    // naive - better?
    // not true for -0.0 !!! so bit manipulation is better
    // if (x < 0) return -x;
    // return x;

    // bitwise (voodoo magic)
    long long bits;
    dm_memcpy(&bits, &x, sizeof(bits));
    bits &= ~(1ULL << 63); // clear the sign bit
    dm_memcpy(&x, &bits, sizeof(x));
    return x;
}

double dm_exp(double x) {
    // Taylor series with 20 terms (closest to original exp())
    double res = 1.0;
    for (int i = 1; i <= 20; i++) {
        res += (natural_pow(x, i) / (factorial(i)));
    }
    return res;
}

double dm_fmax(double x, double y) {
    // nan check
    if (dm_isnan(x)) return y;
    if (dm_isnan(y)) return x;
    
    // inf check
    if (dm_isinf(x) > 0) return x;
    if (dm_isinf(y) > 0) return y;

    return (x > y) ? x : y;
}

// blank until I implement other basic functions
double dm_log(double x) {
    if (x < 0) {
        return dm_nan();
    } else if (x == 0) {
        return dm_inf();
    } else if  (x < EPSILON) {
        return -dm_inf();
    }
    return 0;
}
