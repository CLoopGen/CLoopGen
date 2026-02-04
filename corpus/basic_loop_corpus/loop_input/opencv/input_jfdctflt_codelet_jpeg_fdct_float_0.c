#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

float tmp0;
float tmp1;
float tmp2;
float tmp3;
float tmp4;
float tmp5;
float tmp6;
float tmp7;
float tmp10;
float tmp11;
float tmp12;
float tmp13;
float z1;
float z2;
float z3;
float z4;
float z5;
float z11;
float z13;
float *dataptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01s runtime
static float data[DATA_SIZE];

void init_vars() {
    for (size_t i = 0; i < DATA_SIZE; i++) {
        data[i] = (float)(i % 100) * 0.01f;
    }
    dataptr = data;
    ctr = 8 - 1;
}