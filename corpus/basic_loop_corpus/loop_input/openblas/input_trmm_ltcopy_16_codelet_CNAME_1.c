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
float *a09;
float *a10;
float *a11;
float *a12;
float *a13;
float *a14;
float *a15;
float *a16;

void init_vars() {
    const BLASLONG vector_size = 16;
    const size_t total_data_size = 1 << 20; // ~1MB of data per array
    const BLASLONG n_vectors = total_data_size / (vector_size * sizeof(float));
    
    i = (n_vectors > 0) ? n_vectors : 1;

    lda = vector_size;

    b = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    
    a01 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a02 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a03 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a04 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a05 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a06 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a07 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a08 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a09 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a10 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a11 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a12 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a13 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a14 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a15 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));
    a16 = (float*)aligned_alloc(64, i * vector_size * sizeof(float));

    for (BLASLONG j = 0; j < i * vector_size; j++) {
        b[j] = 0.0f;
        a01[j] = 1.0f;
        a02[j] = 2.0f;
        a03[j] = 3.0f;
        a04[j] = 4.0f;
        a05[j] = 5.0f;
        a06[j] = 6.0f;
        a07[j] = 7.0f;
        a08[j] = 8.0f;
        a09[j] = 9.0f;
        a10[j] = 10.0f;
        a11[j] = 11.0f;
        a12[j] = 12.0f;
        a13[j] = 13.0f;
        a14[j] = 14.0f;
        a15[j] = 15.0f;
        a16[j] = 16.0f;
    }
}