#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint16_t *dst;
uint16_t *src;
int A;
int i;
int E;
ptrdiff_t step;

#define DATA_SIZE (64 * 1024 * 1024) // ~64MB of data to target ~0.01s runtime

static uint16_t internal_src[DATA_SIZE / sizeof(uint16_t)];
static uint16_t internal_dst[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 31;
    stride = 8; // each loop writes 8 elements, then steps by stride
    step = 16;
    h = (DATA_SIZE / sizeof(uint16_t)) / stride; // ensure we don't overflow

    // Initialize pointers
    src = internal_src;
    dst = internal_dst;

    // Seed source array with non-zero values for meaningful computation
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&init_vars));
    for (int j = 0; j < DATA_SIZE / sizeof(uint16_t); j++) {
        internal_src[j] = rand() & 0xFFFF;
        internal_dst[j] = 0;
    }
}