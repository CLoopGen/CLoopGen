#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int kmax;
double *fc_array;
int k;

void init_vars() {
    kmax = 13421772; // Approximately 100 million iterations to target ~0.01 sec runtime
    fc_array = (double *)calloc((kmax + 1), sizeof(double));
    k = 0;
}