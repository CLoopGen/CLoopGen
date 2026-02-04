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
    // Variant 2: Strided memory access - process columns first, then rows (transpose-like access pattern)
    int start_y = block_h * mb_y;
    int end_y = (h > block_h * (mb_y + 1)) ? block_h * (mb_y + 1) : h;
    int num_rows = end_y - start_y;

    // Create a strided access: iterate over x first, then y with non-unit stride in buffer
    for (x = 0; x < w; x++) {
        for (int dy = 0; dy < num_rows; dy++) {
            int y = start_y + dy;
            // Access buf and dst8 with vertical strides
            int v = buf[x + y * w] + (128 << 4) + (1 << (4 - 1));
            v >>= 4;
            if (v & (~255))
                v = ~(v >> 31);
            dst8[x + y * ref_stride] = v;
        }
    }
}
