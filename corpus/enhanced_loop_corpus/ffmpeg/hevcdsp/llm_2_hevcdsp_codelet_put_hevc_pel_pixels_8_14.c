#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2
    int16_t *d = dst;
    uint8_t *s = src;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width - 1; x += 2) {
            d[x]     = s[x]     << (14 - 8);
            d[x + 1] = s[x + 1] << (14 - 8);
        }
        if (x < width) {
            d[x] = s[x] << (14 - 8);
        }
        s += srcstride;
        d += 64;
    }
}
