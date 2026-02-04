#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp10;
INT32 tmp11;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static const int block_height = 8;
static const int block_width = 8;

void init_vars() {
    data_size = 1 << 20;  // ~1MB of data
    data_buffer = (DCTELEM *)calloc(data_size, sizeof(DCTELEM));
    if (!data_buffer) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }

    dataptr = data_buffer;
}