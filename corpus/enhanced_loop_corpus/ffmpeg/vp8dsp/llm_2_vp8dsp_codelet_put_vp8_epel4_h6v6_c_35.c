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
    // Variant 1: Consecutive memory access with unrolled and reordered computation
    // Instead of accessing tmp with varying offsets, pre-load a local window for spatial locality
    for (y = 0; y < h; y++) {
        uint8_t window[8]; // Extended buffer to cover x-8 to x+7 (centered at x)
        for (int i = 0; i < 8; i++) {
            window[i] = tmp[i - 2 * 4]; // preload tmp[x + i - 2*4] relative to base
        }
        for (x = 0; x < 4; x++) {
            int val = filter[2] * window[x + 2] - filter[1] * window[x + 1] +
                      filter[0] * window[x + 0] + filter[3] * window[x + 3] -
                     filter[4] * window[x + 4] + filter[5] * window[x + 5];
            dst[x] = cm[(val + 64) >> 7];
        }
        dst += dststride;
        tmp += 4;
    }
}
