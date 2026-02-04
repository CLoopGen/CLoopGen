#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data
static float global_data[DATA_SIZE];
static float b_data[DATA_SIZE];

void init_vars() {
    lda = 16;
    a01 = global_data;
    b = b_data;

    for (int i = 0; i < DATA_SIZE; i++) {
        global_data[i] = (float)(i % 1000) / 10.0f;
        b_data[i] = 0.0f;
    }
}