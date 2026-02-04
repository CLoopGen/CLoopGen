#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
ptrdiff_t stride;
int b_h;
int y;
unsigned int color4;

void init_vars() {
    const size_t total_size = 16 * 1024 * 1024; // 16 MB for ~0.01 sec runtime estimate
    const int elements_per_row = 8; // 8 writes of 4 bytes each (32 bytes per row)
    const size_t element_size = sizeof(uint32_t);
    const size_t row_size = elements_per_row * element_size;

    b_h = total_size / row_size;
    if (b_h == 0) b_h = 1;
    stride = row_size;

    dst = aligned_alloc(32, (size_t)b_h * stride);
    if (!dst) {
        exit(1);
    }

    color4 = 0xABCDEF00;
}

__attribute__((destructor))
static void cleanup() {
    free(dst);
}