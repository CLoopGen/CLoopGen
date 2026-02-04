#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG m = 100000;
BLASLONG lda = 16;
float *b;
BLASLONG i;
BLASLONG ii = 16;
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
float *a9;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

void init_vars() {
    const size_t total_size = m * 16 * sizeof(float);
    float *data_region = (float *)aligned_alloc(64, total_size + 16 * sizeof(float));
    if (!data_region) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    a1 = data_region;
    a2 = a1 + m;
    a3 = a2 + m;
    a4 = a3 + m;
    a5 = a4 + m;
    a6 = a5 + m;
    a7 = a6 + m;
    a8 = a7 + m;
    a9 = a8 + m;
    a10 = a9 + m;
    a11 = a10 + m;
    a12 = a11 + m;
    a13 = a12 + m;
    a14 = a13 + m;
    a15 = a14 + m;
    a16 = a15 + m;
    b = (float *)aligned_alloc(64, 16 * m * sizeof(float));
    if (!b) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < m; idx++) {
        *(a1 + idx) = 1.0f + idx * 0.0001f;
        *(a2 + idx) = 2.0f + idx * 0.0001f;
        *(a3 + idx) = 3.0f + idx * 0.0001f;
        *(a4 + idx) = 4.0f + idx * 0.0001f;
        *(a5 + idx) = 5.0f + idx * 0.0001f;
        *(a6 + idx) = 6.0f + idx * 0.0001f;
        *(a7 + idx) = 7.0f + idx * 0.0001f;
        *(a8 + idx) = 8.0f + idx * 0.0001f;
        *(a9 + idx) = 9.0f + idx * 0.0001f;
        *(a10 + idx) = 10.0f + idx * 0.0001f;
        *(a11 + idx) = 11.0f + idx * 0.0001f;
        *(a12 + idx) = 12.0f + idx * 0.0001f;
        *(a13 + idx) = 13.0f + idx * 0.0001f;
        *(a14 + idx) = 14.0f + idx * 0.0001f;
        *(a15 + idx) = 15.0f + idx * 0.0001f;
        *(a16 + idx) = 16.0f + idx * 0.0001f;
    }

    for (size_t idx = 0; idx < 16 * m; idx++) {
        b[idx] = 0.0f;
    }
}