#include <stdlib.h>
#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *a01;
float *a02;
float *a03;
float *a04;

static float *b_data;
static float *a_data;

void init_vars() {
    const int vector_length = 8;
    const int matrix_width = 4;
    const size_t data_size_per_row = matrix_width * sizeof(float);
    
    i = 1000000 / (vector_length * sizeof(float));
    if (i == 0) i = 1;
    
    lda = vector_length;

    size_t total_a_size = i * data_size_per_row;

    a_data = (float*)aligned_alloc(32, total_a_size);
    b_data = (float*)aligned_alloc(32, i * vector_length * sizeof(float));

    for (size_t j = 0; j < total_a_size / sizeof(float); j++) {
        a_data[j] = 1.0f;
    }
    for (size_t j = 0; j < i * vector_length; j++) {
        b_data[j] = 0.0f;
    }

    a01 = a_data + 0;
    a02 = a_data + 1;
    a03 = a_data + 2;
    a04 = a_data + 3;
    b = b_data;
}