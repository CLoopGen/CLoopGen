#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int kmax;
double x;
double *fc_array;
int k;

void init_vars() {
    kmax = 13421772;  // Approximately 100 million elements for ~0.01 sec runtime
    x = 2.5;
    fc_array = (double *)aligned_alloc(32, (kmax + 1) * sizeof(double));
    for (int i = 0; i <= kmax; i++) {
        fc_array[i] = (double)(i % 1000) + 1.0;
    }
}