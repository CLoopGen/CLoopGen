#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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
static size_t num_iterations;

void init_vars() {
    const size_t total_data_bytes = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec on modern CPU)
    data_size = total_data_bytes / sizeof(DCTELEM);
    
    // Ensure data_size is multiple of 8 (since loop processes 8 elements per iteration)
    data_size = (data_size / 8) * 8;
    num_iterations = data_size / 8;

    // Allocate aligned buffer for DCTELEM
    data_buffer = (DCTELEM*)aligned_alloc(32, data_size * sizeof(DCTELEM));
    if (!data_buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-zero but predictable values to avoid all-zero optimizations
    for (size_t i = 0; i < data_size; i++) {
        data_buffer[i] = (DCTELEM)((i * 73 + 457) % 1024) - 512;
    }

    // Initialize dataptr to start of buffer
    dataptr = data_buffer;

    // Initialize scalar variables to avoid undefined behavior
    tmp0 = 0; tmp1 = 0; tmp2 = 0; tmp3 = 0;
    tmp4 = 0; tmp5 = 0; tmp6 = 0; tmp7 = 0;
    tmp10 = 0; tmp11 = 0; tmp12 = 0; tmp13 = 0;
    z1 = 0; z2 = 0; z3 = 0; z4 = 0; z5 = 0;
    ctr = 0;
}