#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

#define DATA_SIZE (1 << 20) // 1MB of data: 2^20 elements

uint16_t *lut;
uint16_t *dst;
int dsize;
int i;

void init_vars() {
    dsize = DATA_SIZE;

    lut = (uint16_t *)aligned_alloc(32, sizeof(uint16_t) * (1 << 16));
    dst = (uint16_t *)aligned_alloc(32, sizeof(uint16_t) * dsize);

    if (!lut || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize LUT with identity mapping initially
    for (int idx = 0; idx < (1 << 16); ++idx) {
        lut[idx] = idx & 0xFFFF;
    }

    // Initialize dst with pseudo-random values within valid LUT index range
    srand((unsigned int)time(NULL));
    for (int idx = 0; idx < dsize; ++idx) {
        dst[idx] = rand() & 0xFFFF;
    }
}