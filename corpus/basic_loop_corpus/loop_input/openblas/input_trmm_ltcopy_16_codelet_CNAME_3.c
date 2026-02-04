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
float *a05;
float *a06;
float *a07;
float *a08;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(float))

static float buffer_a[TOTAL_ELEMENTS];
static float buffer_b[8 * (TOTAL_ELEMENTS / (8 * 8))]; // Estimate for b

void init_vars() {
    lda = 8;
    i = (TOTAL_ELEMENTS / 8) / 8; // Ensure we have enough rows and divisible by 8

    a01 = buffer_a;
    a02 = a01 + lda;
    a03 = a02 + lda;
    a04 = a03 + lda;
    a05 = a04 + lda;
    a06 = a05 + lda;
    a07 = a06 + lda;
    a08 = a07 + lda;

    b = buffer_b;

    for (BLASLONG idx = 0; idx < TOTAL_ELEMENTS; idx++) {
        buffer_a[idx] = (float)(idx & 0xFF);
    }
    for (BLASLONG idx = 0; idx < 8 * i; idx++) {
        buffer_b[idx] = 0.0f;
    }
}