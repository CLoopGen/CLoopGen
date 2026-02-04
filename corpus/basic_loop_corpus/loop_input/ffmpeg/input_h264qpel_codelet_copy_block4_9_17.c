#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};

uint8_t *dst;
uint8_t *src;
int dstStride;
int srcStride;
int h;
int i;

#define DATA_SIZE (128 << 20) // 128 MB

void init_vars() {
    src = aligned_alloc(64, DATA_SIZE);
    dst = aligned_alloc(64, DATA_SIZE);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        src[idx] = rand() & 0xFF;
    }

    dstStride = 8;
    srcStride = 8;
    h = DATA_SIZE / 8;
}