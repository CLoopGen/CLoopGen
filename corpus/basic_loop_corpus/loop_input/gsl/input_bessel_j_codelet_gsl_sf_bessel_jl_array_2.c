#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *result_array;
int j;

void init_vars() {
    lmax = 13421772;  // Approximately 100 MB of data (13421772 * 8 bytes per double ≈ 107 MB)
    result_array = (double *)calloc(lmax + 1, sizeof(double));
    if (!result_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}