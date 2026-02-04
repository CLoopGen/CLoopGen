#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 8;
float *b;
BLASLONG i;
BLASLONG ii = 0;
BLASLONG jj = 0;
BLASLONG k;

float *a1;
float *a2;
float *a3;
float *a4;
float *a5;
float *a6;
float *a7;
float *a8;

void init_vars() {
    const BLASLONG total_size = m + 8;
    
    a1 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a2 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a3 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a4 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a5 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a6 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a7 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    a8 = (float*)aligned_alloc(32, sizeof(float) * (total_size));
    b = (float*)aligned_alloc(32, sizeof(float) * (8 * m));

    for (BLASLONG j = 0; j < total_size; j++) {
        a1[j] = 1.0f + j * 0.0001f;
        a2[j] = 2.0f + j * 0.0001f;
        a3[j] = 3.0f + j * 0.0001f;
        a4[j] = 4.0f + j * 0.0001f;
        a5[j] = 5.0f + j * 0.0001f;
        a6[j] = 6.0f + j * 0.0001f;
        a7[j] = 7.0f + j * 0.0001f;
        a8[j] = 8.0f + j * 0.0001f;
    }

    for (BLASLONG j = 0; j < 8 * m; j++) {
        b[j] = 0.0f;
    }

    ii = 0;
    jj = 0;
}