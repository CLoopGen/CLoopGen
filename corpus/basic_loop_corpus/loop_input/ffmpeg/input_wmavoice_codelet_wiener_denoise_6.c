#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float *synth_pf;
int n;
float *coeffs;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of float data (~262k elements)
    synth_pf = (float*)aligned_alloc(32, data_size * sizeof(float));
    coeffs = (float*)aligned_alloc(32, data_size * sizeof(float));

    for (size_t i = 0; i < data_size; i++) {
        synth_pf[i] = (float)((rand() % 1000) / 100.0);
        coeffs[i] = (float)((rand() % 1000) / 100.0);
    }

    n = 1;
}