#include <stdio.h>
#include <inttypes.h>

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

float data_array[8 * 32768]; // 32768 rows of 8 elements each: ~1MB of data
float *dataptr = data_array;
int ctr;

void init_vars() {
    for (int i = 0; i < 8 * 32768; i++) {
        data_array[i] = (float)(i % 16) - 7.5f;
    }
}