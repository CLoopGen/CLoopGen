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
    // Variant 1: Consecutive memory access with manual offset unrolling for better spatial locality
    for (y = 0; y < h; y++) {
        uint8_t s[6];
        // Preload a local block of src to enable consecutive access
        for (int i = 0; i < 6; i++) {
            s[i] = src[i - 1 + srcstride * ((i >= 1) ? 0 : -1)]; // Load from x-1 to x+4 relative base
        }
        for (x = 0; x < 4; x++) {
            int val = filter[2] * s[x + 1] - filter[1] * s[x] +
                      filter[3] * s[x + 2] - filter[4] * s[x + 3];
            dst[x] = cm[(val + 64) >> 7];
        }
        dst += dststride;
        src += srcstride;
    }
}
