#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int nmax;
double *result_array;
int j;

void init_vars() {
    nmax = 13421772;  // Approximately 104 MB of data (13421772 * 8 bytes per double ≈ 107 MB)
    result_array = (double *)calloc((nmax + 1), sizeof(double));
    j = 0;
}