#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(uint16_t))

uint16_t *dst;
int dst_step = 1;

uint16_t *src;
int src_step = 1;

int len = TOTAL_ELEMENTS / 4;  // Ensure we have enough margin for radius and indexing
int radius = 10;
int inv = 12345;
int x = 0;
int sum = 0;

void init_vars() {
    // Allocate memory for src and dst with sufficient padding to prevent out-of-bounds access
    // The loop accesses src[(2 * len - radius - x - 1)] and src[(x - radius - 1)]
    // So we need at least (2 * len + radius) elements in src to cover maximum index
    size_t src_size = 2 * len + radius + 10;
    size_t dst_size = len;

    src = (uint16_t*)aligned_alloc(32, src_size * sizeof(uint16_t));
    dst = (uint16_t*)aligned_alloc(32, dst_size * sizeof(uint16_t));

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize arrays to zero
    memset(src, 0, src_size * sizeof(uint16_t));
    memset(dst, 0, dst_size * sizeof(uint16_t));

    // Seed random number generator and fill src with some data
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&src));
    for (size_t i = 0; i < src_size; i++) {
        src[i] = (uint16_t)(rand() & 0xFFFF);
    }

    // Reset loop counters
    x = 0;
    sum = 0;
}