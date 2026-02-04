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
    const size_t data_size = 16777216; // 16 MB for ~0.01 sec runtime on modern CPU
    pixels = (unsigned char *)aligned_alloc(32, data_size);
    if (!pixels) {
        exit(1);
    }

    for (size_t i = 0; i < data_size; ++i) {
        pixels[i] = (unsigned char)(i & 0xFF);
    }

    row_inc = 4; 
    block_ptr = 0;
    prev_block_ptr = 16; 

    const int total_elements = 16;
    if (prev_block_ptr + total_elements + (3 * row_inc) >= data_size ||
        block_ptr + total_elements + (3 * row_inc) >= data_size) {
        exit(1);
    }
}