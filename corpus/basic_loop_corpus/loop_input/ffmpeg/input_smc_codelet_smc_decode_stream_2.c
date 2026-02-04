#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

unsigned char * pixels;
int pixel_x;
int pixel_y;
int row_inc;
int block_ptr;
int pixel;

void init_vars() {
    const size_t data_size = 16777216; // 16MB
    pixels = (unsigned char *)aligned_alloc(32, data_size);
    if (!pixels) {
        exit(1);
    }

    pixel = 42;
    row_inc = 0;
    block_ptr = 0;
}

__attribute__((destructor))
static void cleanup() {
    free(pixels);
}