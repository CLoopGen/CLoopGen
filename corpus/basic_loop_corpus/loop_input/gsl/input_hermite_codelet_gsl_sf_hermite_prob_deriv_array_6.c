#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int mmax;
double *result_array;
int j;

void init_vars() {
    mmax = 13421772;  // ~100MB of double data (13421772 * 8 bytes ≈ 107MB), ensures ~0.01s runtime
    result_array = (double*)calloc(mmax + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}