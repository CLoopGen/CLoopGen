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
    // Variant 2: Strided memory access pattern
    // Instead of row-major (horizontal) traversal, this variant accesses memory in vertical strides
    // to simulate a different cache access behavior — useful in scenarios where transposed access is needed.

    int start_y = block_h * mb_y;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;

    // Transpose the access: iterate over columns first, then rows
    for (x = 0; x < w; x++) {
        for (y = start_y; y < end_y; y++) {
            int v = buf[x + y * w] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + y * ref_stride] = v;
        }
    }
}
