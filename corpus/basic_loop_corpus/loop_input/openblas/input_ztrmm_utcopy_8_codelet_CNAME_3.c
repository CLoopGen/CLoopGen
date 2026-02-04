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

float *b_buffer;
float *a01_buffer;
float *a02_buffer;
float *a03_buffer;
float *a04_buffer;

void init_vars() {
    BLASLONG elements_per_iter = 8;
    i = 1000000;  
    lda = 8;

    b_buffer = (float*)calloc(elements_per_iter * i, sizeof(float));
    a01_buffer = (float*)calloc((lda * i) + 8, sizeof(float));
    a02_buffer = (float*)calloc((lda * i) + 8, sizeof(float));
    a03_buffer = (float*)calloc((lda * i) + 8, sizeof(float));
    a04_buffer = (float*)calloc((lda * i) + 8, sizeof(float));

    b = b_buffer;
    a01 = a01_buffer;
    a02 = a02_buffer;
    a03 = a03_buffer;
    a04 = a04_buffer;
}