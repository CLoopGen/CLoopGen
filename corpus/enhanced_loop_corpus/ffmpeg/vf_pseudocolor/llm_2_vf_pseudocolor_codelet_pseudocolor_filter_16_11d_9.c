#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive Memory Access with Prefetching and Linear Indexing
    // Changed 2D indexing to linear traversal with direct pointer arithmetic for better cache locality
    float *lut_local = lut;
    uint16_t *index_ptr = index;
    uint16_t *src_line = src;
    uint16_t *dst_line = dst;
    ptrdiff_t irow_step = ilinesize / sizeof(uint16_t);
    ptrdiff_t srow_step = slinesize / sizeof(uint16_t);
    ptrdiff_t drow_step = dlinesize / sizeof(uint16_t);

    for (int y = 0; y < height; y++) {
        uint16_t *src_px = src_line;
        uint16_t *dst_px = dst_line;
        int iy = y >> 1;
        int iy_offset = iy * irow_step;

        for (int x = 0; x < width; x++) {
            int ix = x >> 1;
            int idx_val = index_ptr[iy_offset + ix];
            float v = lut_local[idx_val];

            if (v >= 0 && v <= max) {
                dst_px[x] = (uint16_t)v;
            } else {
                dst_px[x] = src_px[x];
            }
        }

        src_line += srow_step;
        dst_line += drow_step;
    }
}
