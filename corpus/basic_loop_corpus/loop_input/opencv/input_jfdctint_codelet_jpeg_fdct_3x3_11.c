#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
DCTELEM *dataptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024 / sizeof(DCTELEM)) // ~64MB to target ~0.01s runtime

static DCTELEM data_buffer[DATA_SIZE];

void init_vars() {
    for (int i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = (DCTELEM)(i % 256);
    }
    dataptr = data_buffer;
    ctr = 0;
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
}