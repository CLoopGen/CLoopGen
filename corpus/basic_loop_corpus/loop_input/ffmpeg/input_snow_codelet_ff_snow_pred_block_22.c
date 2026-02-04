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
    b_h = 65536;  // Number of rows
    stride = 16;  // Stride in bytes (aligned for uint32_t writes)
    color4 = 0xCAFEBABE;  // Arbitrary 32-bit color value

    size_t total_size = (size_t)b_h * (size_t)stride;
    dst = aligned_alloc(16, total_size);
    if (!dst) {
        exit(1);
    }
}