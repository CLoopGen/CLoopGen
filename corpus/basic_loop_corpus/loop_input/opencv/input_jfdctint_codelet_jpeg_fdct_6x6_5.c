#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static const int block_count = 6;
static const int stride = 8;
static const int total_elements = block_count * stride;

void init_vars() {
    data_size = 1 << 24; // ~16.7 million elements, roughly 64MB for DCTELEM (int)
    data_buffer = (DCTELEM*)calloc(data_size, sizeof(DCTELEM));
    
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate data buffer\n");
        exit(1);
    }

    // Initialize with non-zero values to ensure meaningful computation
    for (size_t i = 0; i < total_elements && i < data_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }

    dataptr = data_buffer;
    ctr = 0;
}