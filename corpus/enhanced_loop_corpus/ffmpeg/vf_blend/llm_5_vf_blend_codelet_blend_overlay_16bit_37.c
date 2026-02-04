#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int16_t blended;

        // Replace branching with arithmetic control expression
        // Use sign bit to determine path: negative if t >= 32768
        int32_t mask = -(t >= 32768); // All 1s if true, 0 otherwise

        uint32_t normal_prod = (2ULL * t * b) / 65535;
        uint32_t invert_prod = 65535 - (2ULL * (65535 - t) * (65535 - b)) / 65535;

        blended = (mask & invert_prod) | ((~mask) & normal_prod);

        dst[j] = t + (blended - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
