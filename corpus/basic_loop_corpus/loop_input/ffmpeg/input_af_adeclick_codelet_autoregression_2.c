#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int ar_order;
double *k;
double *a;
int i;

void init_vars() {
    ar_order = 131072;  // Approximately 1MB of double data (131072 * 8 bytes per double = ~1MB)

    a = (double*)aligned_alloc(32, (ar_order) * sizeof(double));
    k = (double*)aligned_alloc(32, (ar_order + 1) * sizeof(double));

    for (int j = 0; j < ar_order; j++) {
        a[j] = (double)(j + 1);
    }

    for (int j = 0; j <= ar_order; j++) {
        k[j] = 0.0;
    }
}