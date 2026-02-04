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
INT32 tmp4;
INT32 tmp5;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 tmp14;
INT32 z1;
INT32 z2;
INT32 z3;
DCTELEM *dataptr;
DCTELEM *wsptr;
int ctr;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB to ensure sufficient runtime (~0.01 sec on modern CPU)
#define BLOCK_SIZE 8

static DCTELEM data_buffer[DATA_SIZE];
static DCTELEM ws_buffer[DATA_SIZE];

void init_vars() {
    dataptr = data_buffer;
    wsptr = ws_buffer;
    ctr = 7;

    for (size_t i = 0; i < DATA_SIZE; i++) {
        data_buffer[i] = (DCTELEM)(i % 257); // Fill with non-zero pattern within DCT coefficient range
        ws_buffer[i] = (DCTELEM)((i + 13) % 251);
    }
}