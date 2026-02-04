#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

int i;
int band_size = 65536; 
float err_x;
float err_y;
float *X;
float *X_orig;
float *Y;
float *Y_orig;

void init_vars() {
    size_t data_size = band_size * sizeof(float);

    X = (float*)aligned_alloc(32, data_size);
    X_orig = (float*)aligned_alloc(32, data_size);
    Y = (float*)aligned_alloc(32, data_size);
    Y_orig = (float*)aligned_alloc(32, data_size);

    for (int idx = 0; idx < band_size; idx++) {
        X[idx] = (float)(idx % 1000) + 0.5f;
        X_orig[idx] = (float)(idx % 1000) + 0.3f;
        Y[idx] = (float)((idx + 100) % 900) + 0.7f;
        Y_orig[idx] = (float)((idx + 100) % 900) + 0.4f;
    }

    err_x = 0.0f;
    err_y = 0.0f;
    i = 0;
}