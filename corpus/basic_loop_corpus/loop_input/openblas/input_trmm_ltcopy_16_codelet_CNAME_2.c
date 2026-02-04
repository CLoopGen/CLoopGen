#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data

static float global_a_data[DATA_SIZE];
static float global_b_data[DATA_SIZE];

void init_vars() {
    lda = 8; // stride matches the inner loop width
    a01 = global_a_data;
    b = global_b_data;
}