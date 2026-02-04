#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double lower = 1.5;
double *a;

void init_vars() {
    const size_t data_size = 268435456; // 256 MB
    a = (double*)aligned_alloc(32, data_size * sizeof(double));
    if (!a) {
        exit(1);
    }
    for (int j = 0; j < 9; j++) {
        a[j] = 0.0;
    }
}