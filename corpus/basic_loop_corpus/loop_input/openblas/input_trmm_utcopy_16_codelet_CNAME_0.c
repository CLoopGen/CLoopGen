#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data

static float global_a_buffer[DATA_SIZE];
static float global_b_buffer[DATA_SIZE];

void init_vars() {
    lda = 16;
    a01 = global_a_buffer;
    b = global_b_buffer;

    for (int i = 0; i < DATA_SIZE; i++) {
        global_a_buffer[i] = (float)(i & 511) + 1.0f;
        global_b_buffer[i] = 0.0f;
    }
}