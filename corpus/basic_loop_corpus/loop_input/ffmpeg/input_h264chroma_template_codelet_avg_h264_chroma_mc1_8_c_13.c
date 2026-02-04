#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

ptrdiff_t stride;
int h;
uint8_t *dst;
uint8_t *src;
int A;
int i;
int E;
int step;

#define DATA_SIZE (128 << 20) // 128 MB

static uint8_t internal_dst[DATA_SIZE];
static uint8_t internal_src[DATA_SIZE];

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 31;
    step = 4;
    h = 1000000; // Adjust to ensure loop runs ~0.01 sec (tuned for typical CPU)
    stride = 128; // Ensures good stride and fits within data

    // Validate that memory accesses are within bounds
    // Maximum index used: src[step + 0] => src[step], so need at least (h * stride) + step bytes
    if ((h * stride) + step >= DATA_SIZE) {
        h = (DATA_SIZE - step) / stride;
    }

    // Initialize pointers
    dst = internal_dst;
    src = internal_src;

    // Initialize source data to prevent undefined behavior
    for (int j = 0; j < DATA_SIZE; j++) {
        internal_src[j] = rand() & 0xFF;
        internal_dst[j] = rand() & 0xFF;
    }
}