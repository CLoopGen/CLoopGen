#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
int m;
double *result_array;
int ell;

void init_vars() {
    m = 0;
    lmax = 13421772; // Approximately 100MB of data: 13421772 * 8 bytes per double ≈ 107 MB
    result_array = (double*)calloc(lmax - m + 1, sizeof(double));
    if (!result_array) {
        exit(1);
    }
}