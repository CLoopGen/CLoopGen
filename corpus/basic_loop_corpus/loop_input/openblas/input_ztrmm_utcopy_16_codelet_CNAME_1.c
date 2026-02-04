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
    const BLASLONG n_elements = 32;
    const BLASLONG n_iters = 10000;
    const size_t total_size = n_iters * n_elements * sizeof(float);

    float *ptr = (float *)aligned_alloc(32, total_size);
    if (!ptr) {
        exit(1);
    }

    lda = n_elements;
    i = n_iters;
    b = ptr;

    a01 = ptr + 0;
    a02 = ptr + 1;
    a03 = ptr + 2;
    a04 = ptr + 3;
    a05 = ptr + 4;
    a06 = ptr + 5;
    a07 = ptr + 6;
    a08 = ptr + 7;
    a09 = ptr + 8;
    a10 = ptr + 9;
    a11 = ptr + 10;
    a12 = ptr + 11;
    a13 = ptr + 12;
    a14 = ptr + 13;
    a15 = ptr + 14;
    a16 = ptr + 15;

    for (size_t idx = 0; idx < total_size / sizeof(float); ++idx) {
        ptr[idx] = (float)(idx % 1000) + 1.0f;
    }
}