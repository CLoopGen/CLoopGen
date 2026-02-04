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
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic Unrolling
    // We process two elements at once to promote consecutive memory access and reduce indexing overhead.
    uint8_t *idx_row = index;
    uint8_t *src_row = src;
    uint8_t *dst_row = dst;
    
    for (y = 0; y < height; y++) {
        uint8_t *idx = idx_row;
        uint8_t *s = src_row;
        uint8_t *d = dst_row;
        
        x = 0;
        // Process two elements per iteration for better spatial locality
        for (; x < width - 1; x += 2) {
            int v1 = lut[idx[x >> 1]];
            int v2 = lut[idx[(x + 1) >> 1]];

            d[x]     = (v1 >= 0 && v1 <= max) ? v1 : s[x];
            d[x + 1] = (v2 >= 0 && v2 <= max) ? v2 : s[x + 1];
        }
        // Handle remaining element if width is odd
        if (x < width) {
            int v = lut[idx[x >> 1]];
            d[x] = (v >= 0 && v <= max) ? v : s[x];
        }

        idx_row += ilinesize;
        src_row += slinesize;
        dst_row += dlinesize;
    }
}
