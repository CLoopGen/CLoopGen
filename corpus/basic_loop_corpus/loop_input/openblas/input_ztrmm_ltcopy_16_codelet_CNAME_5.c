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

static float *b_base;
static float *a01_base;
static float *a02_base;
static float *a03_base;
static float *a04_base;

#define DATA_SIZE (64 * 1024 * 1024)

void init_vars() {
    b_base = (float*)aligned_alloc(32, DATA_SIZE);
    a01_base = (float*)aligned_alloc(32, DATA_SIZE);
    a02_base = (float*)aligned_alloc(32, DATA_SIZE);
    a03_base = (float*)aligned_alloc(32, DATA_SIZE);
    a04_base = (float*)aligned_alloc(32, DATA_SIZE);

    lda = 8;
    i = (DATA_SIZE / sizeof(float)) / 8;
    ii = 0;

    a01 = a01_base;
    a02 = a02_base;
    a03 = a03_base;
    a04 = a04_base;
    b = b_base;
}