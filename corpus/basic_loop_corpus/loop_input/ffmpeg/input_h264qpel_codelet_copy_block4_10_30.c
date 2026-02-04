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
    const int element_size = 8; // each access is 8 bytes via uint64_t
    h = DATA_SIZE / element_size;
    dstStride = element_size;
    srcStride = element_size;

    src = aligned_alloc(8, (size_t)h * dstStride);
    dst = aligned_alloc(8, (size_t)h * dstStride);

    if (!src || !dst) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int idx = 0; idx < h; idx++) {
        ((uint64_t*)src)[idx] = rand();
    }
}