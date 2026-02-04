#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int lmax;
double *jl_x;
int j;

void init_vars() {
    lmax = 13421772;  // Approximately 100MB of data (13421772 * 8 bytes per double ≈ 107 MB)
    jl_x = (double *)calloc(lmax + 1, sizeof(double));
    if (!jl_x) {
        exit(1);
    }
    j = 0;
}