#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with indirect addressing through index array
    // Simulate irregular but predictable access pattern using a precomputed offset array
    // This mimics scenarios where data layout is non-contiguous or padded
    int offsets[4] = {0, 1, 2, 3}; // Logical column indices
    for (y = 0; y < h + 4 - 1; y++) {
        for (x = 0; x < 4; x++) {
            int off = offsets[x];
            tmp[x] = cm[(filter[2] * src[off + 0] -
                         filter[1] * src[off - 1] +
                         filter[3] * src[off + 1] -
                         filter[4] * src[off + 2] + 64) >> 7];
        }
        tmp += 4;
        src += srcstride;
    }
}
