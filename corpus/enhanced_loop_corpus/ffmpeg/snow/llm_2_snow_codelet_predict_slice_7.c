#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *buf;
extern int mb_y;
extern int x;
extern int y;
extern int block_h;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access Pattern
    // Instead of row-major (consecutive per row), access elements with a stride equal to the width,
    // effectively processing one column at a time, still covering all elements.
    int total_elements = w * (((h) > (block_h * (mb_y + 1)) ? (block_h * (mb_y + 1)) : (h)));
    int start_idx = block_h * mb_y * w;
    for (int stride_offset = 0; stride_offset < w; stride_offset++) {
        for (int base = start_idx + stride_offset; base < start_idx + total_elements; base += w) {
            buf[base] -= 128 << 4;
        }
    }
}
