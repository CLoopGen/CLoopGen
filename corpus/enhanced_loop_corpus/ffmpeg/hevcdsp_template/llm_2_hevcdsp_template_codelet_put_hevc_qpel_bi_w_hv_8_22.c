#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int height;
extern int width;
extern int x;
extern int y;
extern  int8_t *filter;
extern uint8_t *src;
extern ptrdiff_t srcstride;
extern int16_t *tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled accumulation to improve spatial locality
    for (y = 0; y < height + 7; y++) {
        int8_t *f = filter;
        uint8_t *s = src - 3;
        int16_t *t = tmp;
        // Unroll the filter taps and access source consecutively relative to base pointer
        for (x = 0; x < width; x++) {
            int32_t sum = f[0] * s[x + 0] +
                          f[1] * s[x + 1] +
                          f[2] * s[x + 2] +
                          f[3] * s[x + 3] +
                          f[4] * s[x + 4] +
                          f[5] * s[x + 5] +
                          f[6] * s[x + 6] +
                          f[7] * s[x + 7];
            t[x] = sum >> 0;  // Equivalent shift as original (8-8)=0
        }
        src += srcstride;
        tmp += 64;
    }
}
