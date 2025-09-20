#include "dm_math.h"
#include "dm_string.h"
// TODO: add checks for nan, -inf and +inf in each func

double dm_gen_quiet_nan() {
    long long unsigned bits = 0x7ff8000000000000ULL;
    double nan_val;
    dm_memcpy(&nan_val, &bits, sizeof(nan_val));
    return nan_val;
}

double dm_gen_inf(int sign) {
    long long unsigned bits = 0;
    double inf;
    if (sign == 0) {
        // positive inf
        bits = 0x7FF0000000000000ULL;
    } else {
        // negative inf
        bits = 0xFFF0000000000000ULL;
    }
    dm_memcpy(&inf, &bits, sizeof(inf));
    return inf;
}

double dm_fabs(double x) {
    // naive - better?
    // if (x < 0) return -x;
    // return x;

    // bitwise (voodoo magic)
    long long bits;
    dm_memcpy(&bits, &x, sizeof(bits));
    bits &= ~(1ULL << 63); // clear the sign bit
    dm_memcpy(&x, &bits, sizeof(x));
    return x;
}

double dm_log(double x) {
    if (x < 0) {
        return dm_gen_quiet_nan();
    } else if (x == 0) {
        return dm_gen_inf(1);
    } else if  (x < EPSILON) {
        return dm_gen_inf(1);
    }
    return 0;
}
