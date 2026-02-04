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

float *b_data;
float *a01_data;
float *a02_data;
float *a03_data;
float *a04_data;

void init_vars() {
    BLASLONG rows = 100000;
    BLASLONG cols_a = 8;
    BLASLONG cols_b = 8;

    lda = cols_a;
    i = rows;

    b_data = (float *)calloc(rows * cols_b, sizeof(float));
    a01_data = (float *)calloc(rows * cols_a, sizeof(float));
    a02_data = (float *)calloc(rows * cols_a, sizeof(float));
    a03_data = (float *)calloc(rows * cols_a, sizeof(float));
    a04_data = (float *)calloc(rows * cols_a, sizeof(float));

    b = b_data;
    a01 = a01_data;
    a02 = a02_data;
    a03 = a03_data;
    a04 = a04_data;
}