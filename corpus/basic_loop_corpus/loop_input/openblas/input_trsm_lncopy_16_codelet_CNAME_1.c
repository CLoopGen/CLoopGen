#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 8;
float *b;
BLASLONG i;
BLASLONG ii = 10;
BLASLONG jj = 3;
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
    const size_t total_size = m * 8 * sizeof(float);
    b = (float*)aligned_alloc(32, total_size);
    
    a1 = (float*)aligned_alloc(32, (ii - jj + m) * lda * sizeof(float));
    a2 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a3 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a4 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a5 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a6 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a7 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));
    a8 = (float*)aligned_alloc(32, (m + 10) * sizeof(float));

    for (size_t idx = 0; idx < (ii - jj + m) * lda; idx++) {
        a1[idx] = (idx % 17) ? (float)(1.0f + idx % 7) : 1.0f;
    }
    for (size_t idx = 0; idx < m + 10; idx++) {
        a2[idx] = (float)(2.0f + idx % 5);
        a3[idx] = (float)(3.0f + idx % 5);
        a4[idx] = (float)(4.0f + idx % 5);
        a5[idx] = (float)(5.0f + idx % 5);
        a6[idx] = (float)(6.0f + idx % 5);
        a7[idx] = (float)(7.0f + idx % 5);
        a8[idx] = (float)(8.0f + idx % 5);
    }
    for (size_t idx = 0; idx < total_size / sizeof(float); idx++) {
        b[idx] = 0.0f;
    }
}