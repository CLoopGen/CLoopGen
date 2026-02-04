#include <stdio.h>
#include <stdlib.h>

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

#define OUTER_LOOPS 10000
#define INNER_SIZE 16

void init_vars() {
    lda = INNER_SIZE;
    i = OUTER_LOOPS;

    b = (float*)calloc(OUTER_LOOPS * INNER_SIZE, sizeof(float));
    if (!b) exit(1);

    float *base_a1 = (float*)calloc(8 * OUTER_LOOPS * lda, sizeof(float));
    if (!base_a1) exit(1);

    a01 = base_a1 + 0 * OUTER_LOOPS * lda;
    a02 = base_a1 + 1 * OUTER_LOOPS * lda;
    a03 = base_a1 + 2 * OUTER_LOOPS * lda;
    a04 = base_a1 + 3 * OUTER_LOOPS * lda;
    a05 = base_a1 + 4 * OUTER_LOOPS * lda;
    a06 = base_a1 + 5 * OUTER_LOOPS * lda;
    a07 = base_a1 + 6 * OUTER_LOOPS * lda;
    a08 = base_a1 + 7 * OUTER_LOOPS * lda;

    for (BLASLONG j = 0; j < 8; j++) {
        float *ptr = base_a1 + j * OUTER_LOOPS * lda;
        for (BLASLONG k = 0; k < OUTER_LOOPS; k++) {
            for (BLASLONG m = 0; m < lda; m++) {
                ptr[k * lda + m] = (float)(j + k + m);
            }
        }
    }

    for (BLASLONG k = 0; k < OUTER_LOOPS * INNER_SIZE; k++) {
        b[k] = 0.0f;
    }
}