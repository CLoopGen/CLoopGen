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
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec target)
    b_h = 16384; // Number of rows
    stride = total_data_size / b_h; // Ensure total size is respected

    if (stride < 8) {
        stride = 8; // Minimum stride to fit two uint32_t writes (8 bytes)
        b_h = total_data_size / stride;
    }

    dst = aligned_alloc(32, total_data_size);
    if (!dst) exit(1);

    color4 = 0xDEADBEEF;

    for (int i = 0; i < b_h; i++) {
        for (int j = 0; j < stride; j++) {
            dst[i * stride + j] = 0;
        }
    }
}