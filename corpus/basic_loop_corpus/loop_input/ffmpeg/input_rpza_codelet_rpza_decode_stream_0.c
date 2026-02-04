#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int row_inc;
uint16_t colorA;
uint16_t *pixels;
int block_ptr;
int pixel_x;
int pixel_y;

void init_vars() {
    const size_t data_size = 1 << 20; // 1MB of data (adjustable)
    pixels = aligned_alloc(32, data_size);
    if (!pixels) {
        exit(1);
    }

    colorA = 0x7B5D;
    block_ptr = 0;
    row_inc = 4; // Advance by 4 to skip a 4-pixel row after inner loop

    // Ensure the buffer is large enough: we access up to block_ptr + 4*4 + 3*row_inc
    // Max index: 4 rows * 4 cols + 3 * row_inc offset = 16 + 3*4 = 28
    // So we need at least 29 elements, but we allocated much more (data_size / sizeof(uint16_t))
}

// Reset block_ptr and other state if needed before calling loop
void reset_state() {
    block_ptr = 0;
    pixel_x = 0;
    pixel_y = 0;
}