#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 16;
float *b;
BLASLONG i;
BLASLONG ii = 15;
BLASLONG jj = 10;
BLASLONG k;

float *a1;
float *a2;
float *a3;
float *a4;
float *a5;
float *a6;
float *a7;
float *a8;
float *a9;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

void init_vars() {
    const BLASLONG total_size = m + 16;
    
    a1 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a2 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a3 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a4 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a5 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a6 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a7 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a8 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a9 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a10 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a11 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a12 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a13 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a14 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a15 = (float*)aligned_alloc(64, total_size * sizeof(float));
    a16 = (float*)aligned_alloc(64, total_size * sizeof(float));
    b = (float*)aligned_alloc(64, 16 * m * sizeof(float));

    for (BLASLONG j = 0; j < total_size; j++) {
        a1[j] = 1.0f + j * 0.0001f;
        a2[j] = 2.0f + j * 0.0001f;
        a3[j] = 3.0f + j * 0.0001f;
        a4[j] = 4.0f + j * 0.0001f;
        a5[j] = 5.0f + j * 0.0001f;
        a6[j] = 6.0f + j * 0.0001f;
        a7[j] = 7.0f + j * 0.0001f;
        a8[j] = 8.0f + j * 0.0001f;
        a9[j] = 9.0f + j * 0.0001f;
        a10[j] = 10.0f + j * 0.0001f;
        a11[j] = 11.0f + j * 0.0001f;
        a12[j] = 12.0f + j * 0.0001f;
        a13[j] = 13.0f + j * 0.0001f;
        a14[j] = 14.0f + j * 0.0001f;
        a15[j] = 15.0f + j * 0.0001f;
        a16[j] = 16.0f + j * 0.0001f;
    }

    for (BLASLONG j = 0; j < 16 * m; j++) {
        b[j] = 0.0f;
    }

    ii = jj + 5;
}