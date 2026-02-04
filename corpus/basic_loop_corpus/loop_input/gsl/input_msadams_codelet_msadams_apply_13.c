#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double * hprev;
size_t i;

void init_vars() {
    const size_t data_size = 134217728; // 128 MB of data (~134M doubles)
    hprev = (double *)aligned_alloc(32, data_size * sizeof(double));
    if (!hprev) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        hprev[idx] = (double)(idx & 255);
    }
}