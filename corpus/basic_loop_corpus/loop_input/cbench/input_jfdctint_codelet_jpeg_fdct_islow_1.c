#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef long INT32;
typedef int DCTELEM;

INT32 tmp0;
INT32 tmp1;
INT32 tmp2;
INT32 tmp3;
INT32 tmp4;
INT32 tmp5;
INT32 tmp6;
INT32 tmp7;
INT32 tmp10;
INT32 tmp11;
INT32 tmp12;
INT32 tmp13;
INT32 z1;
INT32 z2;
INT32 z3;
INT32 z4;
INT32 z5;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static int num_iterations;

void init_vars() {
    data_size = 134217728; // 128 MB of data to target ~0.01 sec runtime
    num_iterations = data_size / (8 * sizeof(DCTELEM));

    data_buffer = (DCTELEM*)aligned_alloc(64, data_size);
    if (!data_buffer) {
        fprintf(stderr, "Failed to allocate data buffer\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(DCTELEM); i++) {
        data_buffer[i] = (DCTELEM)(i % 256 - 128);
    }

    dataptr = data_buffer;
    ctr = 7;
}

__attribute__((destructor))
static void cleanup() {
    if (data_buffer) {
        free(data_buffer);
    }
}