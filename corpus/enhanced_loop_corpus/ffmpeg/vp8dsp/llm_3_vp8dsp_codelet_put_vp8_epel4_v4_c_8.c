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
    // Variant 2: Strided memory access with transposed indexing using pointer arithmetic strides
    ptrdiff_t dstride = dststride / sizeof(uint8_t);
    ptrdiff_t sstride = srcstride / sizeof(uint8_t);
    uint8_t *s_base = src;
    uint8_t *d_base = dst;

    for (y = 0; y < h; y++) {
        for (x = 0; x < 4; x++) {
            // Use strided access via precomputed offsets instead of direct indexing
            uint8_t s_m1 = *(s_base + (y * sstride) + (x - 1));
            uint8_t s_0  = *(s_base + (y * sstride) + (x + 0));
            uint8_t s_p1 = *(s_base + (y * sstride) + (x + 1));
            uint8_t s_p2 = *(s_base + (y * sstride) + (x + 2));

            int filtered = filter[2] * s_0 - filter[1] * s_m1 +
                           filter[3] * s_p1 - filter[4] * s_p2;
            *(d_base + y * dstride + x) = cm[(filtered + 64) >> 7];
        }
    }
}
