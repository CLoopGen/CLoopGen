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

static DCTELEM *data_buffer;
static size_t data_size;
static const int block_height = 8;
static const int total_blocks = 32768;

void init_vars() {
    data_size = total_blocks * block_height * sizeof(DCTELEM);
    data_buffer = (DCTELEM *)calloc(total_blocks, block_height * sizeof(DCTELEM));
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }
    
    for (size_t i = 0; i < total_blocks * block_height; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }

    dataptr = data_buffer;
    ctr = 8 - 1;
    tmp0 = 0;
    tmp1 = 0;
    tmp2 = 0;
    tmp3 = 0;
    tmp10 = 0;
    tmp11 = 0;
    tmp12 = 0;
    tmp13 = 0;
    z1 = 0;
}