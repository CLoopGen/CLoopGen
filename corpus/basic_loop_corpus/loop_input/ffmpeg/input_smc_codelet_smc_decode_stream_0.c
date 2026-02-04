#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char * pixels;
int pixel_x;
int pixel_y;
int row_inc;
int block_ptr;
int prev_block_ptr;

void init_vars() {
    const size_t data_size = 16777216; // 16MB of data
    pixels = (unsigned char *)malloc(data_size);
    if (!pixels) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; i++) {
        pixels[i] = (unsigned char)(i & 0xFF);
    }

    block_ptr = 0;
    prev_block_ptr = 4;
    row_inc = 16 - 4;
}