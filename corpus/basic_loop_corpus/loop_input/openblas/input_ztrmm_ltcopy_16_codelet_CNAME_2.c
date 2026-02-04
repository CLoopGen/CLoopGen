#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data
static float buffer_a[DATA_SIZE];
static float buffer_b[DATA_SIZE];

void init_vars() {
    lda = 16;
    a01 = buffer_a;
    b = buffer_b;
}