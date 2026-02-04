#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access using pointer arithmetic with fixed increments
    // We restructure the inner loop to iterate through a strided pattern explicitly,
    // simulating a more cache-unfriendly, strided access useful in some SIMD contexts.
    for (y = 0; y < h; y++) {
        uint8_t *d = dst;
        uint8_t *s = src;
        // Access each of the 4 output points with full filter support via stride-offsets
        for (x = 0; x < 4; x++) {
            ptrdiff_t offset0 = (x + 0) * srcstride;
            ptrdiff_t offset1 = (x - 1) * srcstride;
            ptrdiff_t offset2 = (x - 2) * srcstride;
            ptrdiff_t offset3 = (x + 1) * srcstride;
            ptrdiff_t offset4 = (x + 2) * srcstride;
            ptrdiff_t offset5 = (x + 3) * srcstride;

            int sum = filter[2] * s[offset0] - filter[1] * s[offset1] + filter[0] * s[offset2]
                    + filter[3] * s[offset3] - filter[4] * s[offset4] + filter[5] * s[offset5];
            d[x] = cm[(sum + 64) >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
