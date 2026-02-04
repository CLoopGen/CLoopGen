#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *lpc;
double bandwidth_expansion_coeff;
int i;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of float data (~262k elements)
    lpc = (float *)aligned_alloc(32, data_size);
    if (!lpc) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        lpc[idx] = (float)(idx % 1000) / 100.0f;
    }
    bandwidth_expansion_coeff = 0.999;
    i = 0;
}