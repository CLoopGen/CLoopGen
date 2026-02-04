#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmin;
int nmax;
double *result_array;
int n;

void init_vars() {
    nmin = 0;
    nmax = 13421772; // ~107 MB of data (13421772 * 8 bytes per double ≈ 107 MB)
    result_array = (double *)calloc((nmax - nmin + 1), sizeof(double));
    if (!result_array) {
        exit(1);
    }
}