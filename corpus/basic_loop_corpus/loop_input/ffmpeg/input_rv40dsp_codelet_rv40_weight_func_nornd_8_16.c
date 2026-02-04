#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
uint8_t *src1;
uint8_t *src2;
int w1;
int w2;
ptrdiff_t stride;
int i;
int j;

static uint8_t *alloc_aligned(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    const int block_count = 4096;
    const int block_size = 8;
    const int total_elements = block_count * block_size;
    const size_t total_bytes = total_elements * sizeof(uint8_t);

    src1 = alloc_aligned(total_bytes);
    src2 = alloc_aligned(total_bytes);
    dst = alloc_aligned(total_bytes);

    for (size_t k = 0; k < total_bytes; ++k) {
        src1[k] = rand() & 0xFF;
        src2[k] = rand() & 0xFF;
    }

    w1 = 13;
    w2 = 18;
    stride = 8 * sizeof(uint8_t);

    i = 0;
    j = 0;
}