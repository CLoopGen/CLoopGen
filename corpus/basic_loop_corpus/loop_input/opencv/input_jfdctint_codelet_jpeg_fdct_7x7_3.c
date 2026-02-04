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
INT32 z1;
INT32 z2;
INT32 z3;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer = NULL;

void init_vars() {
    const size_t total_size = 256 * 1024 * sizeof(DCTELEM); // ~256 KB of data
    data_buffer = (DCTELEM *)calloc(total_size / sizeof(DCTELEM), sizeof(DCTELEM));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize with non-zero values to ensure meaningful computation
    for (size_t i = 0; i < total_size / sizeof(DCTELEM); i++) {
        data_buffer[i] = (DCTELEM)(i % 256);
    }

    dataptr = data_buffer;
}