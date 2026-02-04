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
int step;

#define DATA_SIZE (128 << 20) // 128 MB of total data

static uint16_t internal_src[DATA_SIZE / sizeof(uint16_t)];
static uint16_t internal_dst[DATA_SIZE / sizeof(uint16_t)];

void init_vars() {
    // Initialize scalar variables
    A = 17;
    E = 31;
    step = 1;
    h = (DATA_SIZE / sizeof(uint16_t)) / 16; // Ensure we stay within bounds
    stride = 16; // Stride in elements (not bytes)

    // Initialize pointers to internal arrays
    src = internal_src;
    dst = internal_dst;

    // Initialize source data to avoid undefined behavior
    for (int j = 0; j < (int)(DATA_SIZE / sizeof(uint16_t)); j++) {
        src[j] = (uint16_t)(j & 0x3FF); // Small values to prevent overflow
    }

    // Clear destination
    memset(dst, 0, DATA_SIZE);
}