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
    // Variant 2: Strided access using index vector (indirect-like indexing with fixed offsets)
    const int offsets[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for (y = 0; y < h; y++) {
        for (int idx = 0; idx < 16; idx++) {
            int x = offsets[idx]; // Simulate indirect access via lookup
            int s0 = src[x + 0 * srcstride];
            int s1 = src[x - 1 * srcstride];
            int s2 = src[x - 2 * srcstride];
            int s3 = src[x + 1 * srcstride];
            int s4 = src[x + 2 * srcstride];
            int s5 = src[x + 3 * srcstride];
            int filtered_val = filter[2] * s0 - filter[1] * s1 + filter[0] * s2 +
                               filter[3] * s3 - filter[4] * s4 + filter[5] * s5;
            dst[x] = cm[(filtered_val + 64) >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
