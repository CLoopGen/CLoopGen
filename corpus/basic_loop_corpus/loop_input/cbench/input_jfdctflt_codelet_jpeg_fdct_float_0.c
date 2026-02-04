#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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

static float data_buffer[8 * 32768]; // ~1MB of float data (8 * 32768 * 4 = 1,048,576 bytes)

void init_vars() {
    dataptr = data_buffer;
    for (int i = 0; i < 8 * 32768; i++) {
        data_buffer[i] = (float)(i % 8) * 0.1f;
    }
    ctr = 8 - 1;
}