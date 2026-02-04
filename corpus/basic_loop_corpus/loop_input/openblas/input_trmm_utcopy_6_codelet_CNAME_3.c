#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG i;
BLASLONG ii;
float *ao1;

float *b_data;
float *ao1_data;

void init_vars() {
    BLASLONG data_size = 64 * 1024 * 1024; // ~256 MB of float data (64M elements)
    b_data = (float*)calloc(data_size, sizeof(float));
    ao1_data = (float*)calloc(data_size, sizeof(float));

    lda = 4;
    i = (data_size / 4) / 2; // Ensure we don't exceed bounds: each iteration accesses 4 elements and increments by lda
    b = b_data;
    ao1 = ao1_data;
}