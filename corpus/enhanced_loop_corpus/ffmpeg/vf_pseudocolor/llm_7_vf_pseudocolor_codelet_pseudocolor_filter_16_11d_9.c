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
    // Eliminate apparent dependencies by privatizing variables and unrolling to break sequential patterns
    for (y = 0; y < height; y++) {
        // Process two pixels per iteration to change data access pattern and reduce loop-carried dependencies
        for (x = 0; x < width - 1; x += 2) {
            int idx0 = index[(y >> 1) * ilinesize + (x >> 1)];
            int idx1 = index[(y >> 1) * ilinesize + ((x+1) >> 1)]; // May be same as idx0 if x is odd, but handled naturally

            int v0 = lut[idx0];
            int v1 = lut[idx1];

            // Remove conditional branching effect on memory stores by precomputing both paths (speculative execution style)
            uint16_t val0 = (v0 >= 0 && v0 <= max) ? v0 : src[x];
            uint16_t val1 = (v1 >= 0 && v1 <= max) ? v1 : src[x+1];

            dst[x]   = val0;
            dst[x+1] = val1;
        }
        // Handle last pixel if width is odd
        if (x < width) {
            int v = lut[index[(y >> 1) * ilinesize + (x >> 1)]];
            dst[x] = (v >= 0 && v <= max) ? v : src[x];
        }
        src += slinesize;
        dst += dlinesize;
    }
}
