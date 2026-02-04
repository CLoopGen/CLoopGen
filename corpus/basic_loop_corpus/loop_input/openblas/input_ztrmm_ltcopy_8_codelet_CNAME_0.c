#include <stdio.h>

typedef long BLASLONG;

BLASLONG lda;
float *b;
BLASLONG ii;
float *a01;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of float data
static float a_data[DATA_SIZE];
static float b_data[DATA_SIZE];

void init_vars() {
    lda = 16;
    ii = 0;
    
    a01 = a_data;
    b = b_data;
}