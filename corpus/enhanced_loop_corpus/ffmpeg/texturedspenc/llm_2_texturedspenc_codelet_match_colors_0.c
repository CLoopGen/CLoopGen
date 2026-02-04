#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *block;
extern ptrdiff_t stride;
extern int dirr;
extern int dirg;
extern int dirb;
extern int dots[16];
extern int stops[4];
extern int x;
extern int y;
extern int k;
extern uint8_t color[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base pointers
    uint8_t *base_block;
    int *dots_ptr = dots;
    for (y = 0; y < 4; y++) {
        base_block = &block[y * stride];
        for (x = 0; x < 4; x++) {
            int offset = x * 4;
            dots_ptr[k++] = base_block[offset + 0] * dirr + base_block[offset + 1] * dirg + base_block[offset + 2] * dirb;
        }
        int color_offset = y * 4;
        stops[y] = color[color_offset + 0] * dirr + color[color_offset + 1] * dirg + color[color_offset + 2] * dirb;
    }
}
