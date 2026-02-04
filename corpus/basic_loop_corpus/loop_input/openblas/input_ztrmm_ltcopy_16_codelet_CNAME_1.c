#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    const size_t total_data_size = 128 * 1024 * 1024; // Aim for ~128MB of data
    const BLASLONG vector_length = 32;
    const int num_arrays = 16;
    const BLASLONG rows = total_data_size / (num_arrays * vector_length * sizeof(float));
    
    lda = vector_length;
    i = rows > 0 ? rows : 1;

    float *ptr;
    if (posix_memalign((void**)&ptr, 64, total_data_size) != 0) {
        exit(1);
    }

    memset(ptr, 0, total_data_size);

    a01 = ptr;
    a02 = a01 + vector_length * i;
    a03 = a02 + vector_length * i;
    a04 = a03 + vector_length * i;
    a05 = a04 + vector_length * i;
    a06 = a05 + vector_length * i;
    a07 = a06 + vector_length * i;
    a08 = a07 + vector_length * i;
    a09 = a08 + vector_length * i;
    a10 = a09 + vector_length * i;
    a11 = a10 + vector_length * i;
    a12 = a11 + vector_length * i;
    a13 = a12 + vector_length * i;
    a14 = a13 + vector_length * i;
    a15 = a14 + vector_length * i;
    a16 = a15 + vector_length * i;

    if ((a16 + vector_length * i) > (ptr + total_data_size)) {
        exit(1);
    }

    b = (float*)malloc(i * vector_length * sizeof(float));
    if (!b) {
        exit(1);
    }
}