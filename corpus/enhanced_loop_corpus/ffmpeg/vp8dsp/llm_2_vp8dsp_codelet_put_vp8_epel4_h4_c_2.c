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
    // Variant 1: Consecutive memory access with unrolled accumulation
    // Instead of accessing src with variable offsets, preload filter-scaled values into temporaries
    // and use consecutive src access pattern for better cache locality.

    for (y = 0; y < h; y++) {
        uint8_t s[6];
        for (int i = 0; i < 6; i++) {
            s[i] = src[i - 1];  // Preload a window of source samples
        }
        for (x = 0; x < 4; x++) {
            int sum = filter[2] * s[x + 1] - filter[1] * s[x] + 
                      filter[3] * s[x + 2] - filter[4] * s[x + 3] + 64;
            dst[x] = cm[sum >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
