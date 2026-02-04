#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef float FLOAT;

#define DATA_SIZE (64 * 1024 * 1024) // ~256MB of data to ensure loop runtime ~0.01s

FLOAT temp[64] = {0};

int16_t *data = NULL;

FLOAT tmp0;
FLOAT tmp1;
FLOAT tmp2;
FLOAT tmp3;
FLOAT tmp4;
FLOAT tmp5;
FLOAT tmp6;
FLOAT tmp7;
FLOAT tmp10;
FLOAT tmp11;
FLOAT tmp12;
FLOAT tmp13;
FLOAT z2;
FLOAT z4;
FLOAT z11;
FLOAT z13;
int i;

void init_vars() {
    // Allocate large enough data array to make the loop take ~0.01 seconds
    // The loop runs 8*8 = 64 iterations per block, and processes 8 elements each time
    // So total number of blocks is DATA_SIZE / 64
    // We allocate 256MB of int16_t -> 128M elements
    data = (int16_t*)aligned_alloc(32, DATA_SIZE * sizeof(int16_t));
    if (!data) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize data with pseudo-random values for realistic computation
    srand((unsigned int)time(NULL));
    for (size_t idx = 0; idx < DATA_SIZE; ++idx) {
        data[idx] = (int16_t)(rand() % 65536 - 32768);
    }

    // Initialize temp array to zero
    for (int j = 0; j < 64; ++j) {
        temp[j] = 0.0f;
    }

    // Initialize all floating point temporaries
    tmp0 = 0.0f;
    tmp1 = 0.0f;
    tmp2 = 0.0f;
    tmp3 = 0.0f;
    tmp4 = 0.0f;
    tmp5 = 0.0f;
    tmp6 = 0.0f;
    tmp7 = 0.0f;
    tmp10 = 0.0f;
    tmp11 = 0.0f;
    tmp12 = 0.0f;
    tmp13 = 0.0f;
    z2 = 0.0f;
    z4 = 0.0f;
    z11 = 0.0f;
    z13 = 0.0f;
    i = 0;
}