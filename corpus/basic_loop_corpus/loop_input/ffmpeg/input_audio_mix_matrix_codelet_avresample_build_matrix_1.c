#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

double *matrix_out;
int stride;
int i;
int j;
double maxcoef;
int in_channels;
int out_channels;

void init_vars() {
    in_channels = 800;
    out_channels = 800;
    stride = in_channels;
    maxcoef = 2.5;

    size_t matrix_size = (size_t)out_channels * stride * sizeof(double);
    matrix_out = (double *)calloc(out_channels, stride * sizeof(double));

    if (!matrix_out) {
        exit(1);
    }

    for (size_t idx = 0; idx < out_channels * stride; idx++) {
        matrix_out[idx] = 1.0 + (idx % 256);
    }
}