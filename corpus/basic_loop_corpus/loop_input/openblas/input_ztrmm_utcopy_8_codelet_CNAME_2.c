#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 << 20) // ~64 MB of data to ensure sufficient runtime

static float global_a_data[DATA_SIZE / sizeof(float)] __attribute__((aligned(32)));
static float global_b_data[DATA_SIZE / sizeof(float)] __attribute__((aligned(32)));

void init_vars() {
    // Initialize array data
    for (int i = 0; i < DATA_SIZE / sizeof(float); i++) {
        global_a_data[i] = (float)(i % 1000) / 1000.0f;
        global_b_data[i] = 0.0f;
    }

    // Set lda to 8 to match the stride in the loop
    lda = 8;

    // Point a01 to the beginning of the input data
    a01 = global_a_data;

    // Point b to the beginning of the output buffer
    b = global_b_data;
}