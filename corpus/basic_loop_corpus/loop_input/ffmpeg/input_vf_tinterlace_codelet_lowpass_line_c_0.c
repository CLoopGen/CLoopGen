#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dstp;
ptrdiff_t width;
uint8_t *srcp;
uint8_t *srcp_above;
uint8_t *srcp_below;
int i;

static uint8_t *alloc_aligned_size(size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, 32, size) != 0) {
        exit(1);
    }
    return (uint8_t *)ptr;
}

void init_vars() {
    width = 64 * 1024 * 1024;

    dstp = alloc_aligned_size(width);
    srcp = alloc_aligned_size(width);
    srcp_above = alloc_aligned_size(width);
    srcp_below = alloc_aligned_size(width);

    for (size_t i = 0; i < width; i++) {
        srcp[i] = rand() & 0xFF;
        srcp_above[i] = rand() & 0xFF;
        srcp_below[i] = rand() & 0xFF;
    }

    i = 0;
}