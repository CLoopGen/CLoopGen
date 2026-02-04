#include <stdlib.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

float *b_data;
float *a01_data;

void init_vars() {
    const BLASLONG total_size = 64 * 1024 * 1024 / sizeof(float); // ~256 MB of floats

    b_data = (float*)calloc(total_size, sizeof(float));
    a01_data = (float*)calloc(total_size, sizeof(float));

    b = b_data;
    a01 = a01_data;
    lda = 16; 
}