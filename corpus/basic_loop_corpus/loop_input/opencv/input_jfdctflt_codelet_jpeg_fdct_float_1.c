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

static float data_buffer[8 * 32768]; // 1MB of data (8 * 32768 floats = 262144 floats ~ 1MB)

void init_vars() {
    size_t i;
    for (i = 0; i < 8 * 32768; i++) {
        data_buffer[i] = (float)(i % 8) * 0.1f;
    }
    dataptr = data_buffer;
    ctr = 0;
}