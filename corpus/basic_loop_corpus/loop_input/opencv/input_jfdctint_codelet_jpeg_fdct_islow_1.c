#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;
typedef JLONG DCTELEM;

JLONG tmp0;
JLONG tmp1;
JLONG tmp2;
JLONG tmp3;
JLONG tmp4;
JLONG tmp5;
JLONG tmp6;
JLONG tmp7;
JLONG tmp10;
JLONG tmp11;
JLONG tmp12;
JLONG tmp13;
JLONG z1;
JLONG z2;
JLONG z3;
JLONG z4;
JLONG z5;
DCTELEM *dataptr;
int ctr;

static DCTELEM *data_buffer;
static size_t data_size;
static size_t num_blocks;

void init_vars() {
    // Aim for ~100ms execution: assume each iteration takes ~100 cycles on modern CPU (~3GHz)
    // 8 iterations per block, ~1e9 cycles/sec => ~10M blocks for 0.01 sec
    // Round to 8MiB of data: 8 * 1048576 = 8,388,608 bytes
    data_size = 8 * 1024 * 1024; // 8MB
    num_blocks = data_size / (8 * sizeof(DCTELEM));
    
    if ((data_size % (8 * sizeof(DCTELEM))) != 0) {
        num_blocks++;
        data_size = num_blocks * 8 * sizeof(DCTELEM);
    }

    data_buffer = (DCTELEM*)aligned_alloc(64, data_size);
    if (!data_buffer) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize buffer with non-zero values to avoid edge cases
    for (size_t i = 0; i < data_size / sizeof(DCTELEM); i++) {
        data_buffer[i] = (DCTELEM)(i * 7919) ^ (i >> 3);
    }

    dataptr = data_buffer;
    ctr = 0;
}