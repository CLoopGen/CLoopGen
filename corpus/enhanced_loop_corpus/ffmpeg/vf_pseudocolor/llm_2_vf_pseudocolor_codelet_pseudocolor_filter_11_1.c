#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access via (y << 1) and (x << 1), precompute base pointers and access index, src, dst consecutively per row.
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    for (y = 0; y < height; y++) {
        uint8_t *index_base = &index[(y << 1) * ilinesize];
        float *lut_ptr = lut;
        uint8_t *src_col = src_row;
        uint8_t *dst_col = dst_row;
        for (x = 0; x < width; x++) {
            int v = lut_ptr[index_base[(x << 1)]];
            if (v >= 0 && v <= max) {
                *dst_col = v;
            } else {
                *dst_col = *src_col;
            }
            src_col++;
            dst_col++;
        }
        src_row += slinesize;
        dst_row += dlinesize;
    }
}
