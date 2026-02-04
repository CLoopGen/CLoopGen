#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;
float *ao2;
float *ao3;
float *ao4;
float *ao5;
float *ao6;
float *ao7;
float *ao8;

static float *create_float_array(size_t n) {
    float *arr = (float *)calloc(n, sizeof(float));
    return arr;
}

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB of float data
    const size_t stride = 2;
    const size_t outputs_per_iter = 16;
    i = total_data_size / outputs_per_iter;

    b = create_float_array(i * outputs_per_iter);

    ao1 = create_float_array(i * stride);
    ao2 = create_float_array(i * stride);
    ao3 = create_float_array(i * stride);
    ao4 = create_float_array(i * stride);
    ao5 = create_float_array(i * stride);
    ao6 = create_float_array(i * stride);
    ao7 = create_float_array(i * stride);
    ao8 = create_float_array(i * stride);
}