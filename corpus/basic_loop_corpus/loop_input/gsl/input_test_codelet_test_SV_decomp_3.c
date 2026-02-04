#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
double carry;
double lower;
double upper;
double *a;

void init_vars() {
    size_t data_size = 1 << 20; // ~8MB of data (1M doubles), sufficient for ~0.01 sec runtime
    a = aligned_alloc(32, data_size * sizeof(double));
    if (!a) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        a[idx] = 0.5;
    }

    i = 16;
    carry = 1.0;
    lower = 0.0;
    upper = 1.0;
}