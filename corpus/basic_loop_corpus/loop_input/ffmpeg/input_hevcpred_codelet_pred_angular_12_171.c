#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

int size = 32768; // Ensures ~128KB of data (32768 * 2 bytes * 2 arrays), fits in L2 cache, runs fast
int x;

uint16_t *left;
uint16_t *ref_tmp;

void init_vars() {
    left = (uint16_t*)aligned_alloc(8, (size + 1) * sizeof(uint16_t));
    ref_tmp = (uint16_t*)aligned_alloc(8, (size + 4) * sizeof(uint16_t)); // extra space for safety

    if (!left || !ref_tmp) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= size; ++i) {
        left[i] = (uint16_t)(i & 0xFFFF);
    }
    for (int i = 0; i <= size + 3; ++i) {
        ref_tmp[i] = 0;
    }
}