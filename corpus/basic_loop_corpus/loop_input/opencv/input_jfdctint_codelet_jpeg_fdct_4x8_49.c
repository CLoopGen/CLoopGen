#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
DCTELEM *dataptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(DCTELEM)) // ~64MB of data

static DCTELEM data[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        data[i] = (DCTELEM)(i % 256 - 128);
    }
    dataptr = data;
}