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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2x
    // This variant processes two elements per iteration to promote consecutive, coalesced memory access
    for (y = 0; y < height; y++) {
        uint16_t *idx_row = index;
        uint16_t *src_row = src;
        uint16_t *dst_row = dst;
        for (x = 0; x < width - 1; x += 2) {
            int v0 = lut[idx_row[x]];
            int v1 = lut[idx_row[x + 1]];

            dst_row[x] = (v0 >= 0 && v0 <= max) ? v0 : src_row[x];
            dst_row[x + 1] = (v1 >= 0 && v1 <= max) ? v1 : src_row[x + 1];
        }
        // Handle remaining element if width is odd
        if (x < width) {
            int v = lut[idx_row[x]];
            dst_row[x] = (v >= 0 && v <= max) ? v : src_row[x];
        }
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
