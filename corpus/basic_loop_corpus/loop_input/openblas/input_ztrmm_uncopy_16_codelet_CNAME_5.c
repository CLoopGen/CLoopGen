#include <stdio.h>

typedef long BLASLONG;

float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float *b_data;
static float *a01_data;
static float *a02_data;
static float *a03_data;
static float *a04_data;

void init_vars() {
    const BLASLONG vector_size = 8;
    const BLASLONG input_chunk = 2;
    const BLASLONG total_operations = 500000;
    
    i = total_operations;

    b_data = (float*)__builtin_malloc(total_operations * vector_size * sizeof(float));
    a01_data = (float*)__builtin_malloc(total_operations * input_chunk * sizeof(float));
    a02_data = (float*)__builtin_malloc(total_operations * input_chunk * sizeof(float));
    a03_data = (float*)__builtin_malloc(total_operations * input_chunk * sizeof(float));
    a04_data = (float*)__builtin_malloc(total_operations * input_chunk * sizeof(float));

    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;

    for (BLASLONG j = 0; j < total_operations * input_chunk; j++) {
        a01_data[j] = 1.0f + j;
        a02_data[j] = 2.0f + j;
        a03_data[j] = 3.0f + j;
        a04_data[j] = 4.0f + j;
    }

    for (BLASLONG j = 0; j < total_operations * vector_size; j++) {
        b_data[j] = 0.0f;
    }
}