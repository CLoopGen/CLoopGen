#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int tmp0;
int tmp1;
int tmp2;
int tmp3;
int tmp4;
int tmp5;
int tmp6;
int tmp7;
int tmp10;
int tmp11;
int tmp12;
int tmp13;
int z1;
int z2;
int z3;
int z4;
int z5;
int z11;
int z13;
int16_t *dataptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to target ~0.01 sec runtime
static int16_t data_buffer[DATA_SIZE];

void init_vars() {
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp3 = 0;
    tmp4 = 0;
    tmp5 = 0;
    tmp6 = 0;
    tmp7 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    z1 = 0;
    z2 = 0;
    z3 = 0;
    z4 = 0;
    z5 = 0;
    z11 = 0;
    z13 = 0;
    ctr = 0;
    dataptr = data_buffer;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = (int16_t)(i % 512);
    }
}