#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *d;
extern ptrdiff_t stride;
extern int x;
extern int y;
extern int ia;
extern int ih;
extern int iv;
extern  uint8_t *cm;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed loop order to change traversal pattern
    ptrdiff_t d_stride_y = stride * 7; // reverse direction: start from last row
    for (y = 7; y >= 0; y--) {
        int iy = 7 - y; // map to original logical index
        int dy_offset = d_stride_y + (iy << 3); // assuming stride is power of two or optimized offset
        int iv_val = (iy - 3) * iv;
        for (x = 0; x < 8; x++) {
            int cm_index = (ia + (x - 3) * ih + iv_val + 16) >> 5;
            d[dy_offset + x] = cm[cm_index];
        }
        d_stride_y -= stride;
    }
}
