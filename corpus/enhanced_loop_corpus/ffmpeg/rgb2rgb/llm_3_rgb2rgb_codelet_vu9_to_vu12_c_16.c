#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src1;
extern uint8_t *dst1;
extern int srcStride1;
extern int dstStride1;
extern int x;
extern int y;
extern int w;
extern int h;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration
    // Modify access pattern by reversing the loop index and accessing memory in strided manner
    // This changes spatial locality and may affect cache behavior.
    // We traverse from w-1 down to 0, and use negative indexing logic via pointer adjustment.

    for (y = 0; y < h; y++) {
        const uint8_t *s1 = src1 + srcStride1 * (y >> 1);
        uint8_t *d = dst1 + dstStride1 * y;
        for (x = w - 1; x >= 0; x--) {
            uint8_t val = s1[x];
            d[2 * x] = val;
            d[2 * x + 1] = val;
        }
    }
}
