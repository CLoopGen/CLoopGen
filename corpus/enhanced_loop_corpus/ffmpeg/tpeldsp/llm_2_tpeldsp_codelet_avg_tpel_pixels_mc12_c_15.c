#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int stride;
extern int width;
extern int height;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic unrolling
    uint8_t *d = dst;
    uint8_t *s = src;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width - 1; j += 2) {
            // Process two elements at once to promote consecutive access
            int val0 = (d[j] + (((3 * s[j] + 2 * s[j + 1] + 4 * s[j + stride] + 3 * s[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
            int val1 = (d[j+1] + (((3 * s[j+1] + 2 * s[j + 2] + 4 * s[j + 1 + stride] + 3 * s[j + stride + 2] + 6) * 2731) >> 15) + 1) >> 1;
            d[j] = (uint8_t)val0;
            d[j+1] = (uint8_t)val1;
        }
        // Handle last element if width is odd
        if (j < width) {
            d[j] = (d[j] + (((3 * s[j] + 2 * s[j + 1] + 4 * s[j + stride] + 3 * s[j + stride + 1] + 6) * 2731) >> 15) + 1) >> 1;
        }
        s += stride;
        d += stride;
    }
}
