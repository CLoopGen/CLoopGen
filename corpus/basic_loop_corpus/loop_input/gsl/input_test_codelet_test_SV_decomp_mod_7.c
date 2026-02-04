#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double carry;
double lower = -1.0;
double upper = 100.0;
double *a;

void init_vars() {
    size_t data_size = 1 << 20;
    a = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!a) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        a[idx] = 50.0 + (idx % 10);
    }
    i = 16;
    carry = 1.0;
    lower = -1.0;
    upper = 100.0;
}