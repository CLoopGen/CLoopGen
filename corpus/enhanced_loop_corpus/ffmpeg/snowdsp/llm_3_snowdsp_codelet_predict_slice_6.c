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
extern int ref_stride;
extern uint8_t *dst8;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with transposed traversal order
    // Instead of row-major, access buffer in column-major fashion with stride handling
    // This changes access pattern to strided across rows for each column

    int start_y = block_h * mb_y;
    int end_y = (h < block_h * (mb_y + 1)) ? h : block_h * (mb_y + 1);

    // Early exit if no work
    if (start_y >= end_y || w == 0) return;

    // Process one column at a time (strided access down the column)
    for (x = 0; x < w; x++) {
        for (y = start_y; y < end_y; y++) {
            // Access buf and dst8 with vertical strides
            int v = buf[x + y * w] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);  // Clamp to 0 or 255 depending on sign
            dst8[x + y * ref_stride] = (uint8_t)v;
        }
    }
}
