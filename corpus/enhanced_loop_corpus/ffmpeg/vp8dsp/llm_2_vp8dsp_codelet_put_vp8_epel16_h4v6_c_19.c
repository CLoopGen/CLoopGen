#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dststride;
extern int h;
extern  uint8_t *filter;
extern  uint8_t *cm;
extern int x;
extern int y;
extern uint8_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of accessing tmp with large strides (±16, ±32, etc.), we reorganize the computation
    // to access consecutive memory locations by pre-loading a local buffer.
    // This improves cache locality and enables better vectorization.

    for (y = 0; y < h; y++) {
        uint8_t local_tmp[24]; // Holds tmp[-2*16] to tmp[+3*16] relative to current block
        for (int i = 0; i < 24; i++) {
            local_tmp[i] = tmp[i - 2 * 16 + 16]; // Shift base so index 0 corresponds to x-2*16
        }
        for (x = 0; x < 16; x++) {
            int val = (filter[2] * local_tmp[x + 2 * 16] -
                       filter[1] * local_tmp[x + 1 * 16] +
                       filter[0] * local_tmp[x + 0 * 16] +
                       filter[3] * local_tmp[x + 3 * 16] -
                       filter[4] * local_tmp[x + 4 * 16] +
                       filter[5] * local_tmp[x + 5 * 16] + 64) >> 7;
            dst[x] = cm[val];
        }
        dst += dststride;
        tmp += 16;
    }
}
