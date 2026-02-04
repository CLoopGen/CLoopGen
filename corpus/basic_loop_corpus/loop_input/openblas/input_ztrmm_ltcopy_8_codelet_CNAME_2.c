#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 << 20) // ~64 MB of data to ensure sufficient runtime

static float a_data[DATA_SIZE / sizeof(float)] __attribute__((aligned(32)));
static float b_data[DATA_SIZE / sizeof(float)] __attribute__((aligned(32)));

void init_vars() {
    // Initialize array data to non-zero values to help detect errors
    for (int i = 0; i < DATA_SIZE / sizeof(float); i++) {
        a_data[i] = (float)(i & 0xFF);
        b_data[i] = 0.0f;
    }

    // Set lda to 8 for stride access in the loop
    lda = 8;

    // Point a01 to the beginning of a_data
    a01 = a_data;

    // Point b to the beginning of b_data
    b = b_data;
}