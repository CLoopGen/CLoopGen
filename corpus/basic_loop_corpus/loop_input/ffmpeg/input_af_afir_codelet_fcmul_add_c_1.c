#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

float *sum;
float *t;
float *c;
ptrdiff_t len;
int n;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M floats, total input ~768MB for three arrays
    len = data_size / 2; // since each element uses two float slots (complex numbers)

    sum = aligned_alloc(32, data_size * sizeof(float));
    t   = aligned_alloc(32, data_size * sizeof(float));
    c   = aligned_alloc(32, data_size * sizeof(float));

    if (!sum || !t || !c) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (ptrdiff_t i = 0; i < data_size; i++) {
        sum[i] = 0.0f;
        t[i]   = (float)(i % 100) * 0.5f;
        c[i]   = (float)((i % 100) + 1) * 0.25f;
    }
}