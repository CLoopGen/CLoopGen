#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int kmax;
double *fc_array;
int k;

void init_vars() {
    kmax = 13421772; // Approximately 100MB of data (13421772 * 8 bytes per double ≈ 107MB)
    fc_array = (double *)calloc(kmax + 1, sizeof(double));
    if (fc_array == NULL) {
        exit(1);
    }
    k = 0;
}