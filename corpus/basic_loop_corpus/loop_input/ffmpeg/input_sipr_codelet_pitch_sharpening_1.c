#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int pitch_lag_int;
float beta;
float *fixed_vector;
int i;

void init_vars() {
    pitch_lag_int = 40;
    beta = 0.85f;
    size_t data_size = 134217728; // 128 MB of float data (~33.5M elements)
    fixed_vector = (float*)aligned_alloc(32, data_size * sizeof(float));
    if (!fixed_vector) {
        exit(1);
    }
    for (size_t idx = 0; idx < data_size; ++idx) {
        fixed_vector[idx] = (float)((idx % 1000) - 500);
    }
}