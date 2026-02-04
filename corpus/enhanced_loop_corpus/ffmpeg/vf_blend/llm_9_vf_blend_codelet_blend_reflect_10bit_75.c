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
    for (j = 0; j < width; j += 4) {
        for (int k = 0; k < 4 && (j + k) < width; k++) {
            int idx = j + k;
            uint16_t t = top[idx];
            uint16_t b = bottom[idx];
            uint16_t computed = (b == 1023) ? 1023 : ((t * t / ((b < 1023) ? (1023 - b) : 1)) > 1023 ? 1023 : (t * t / ((b < 1023) ? (1023 - b) : 1)));
            dst[idx] = t + (computed - t) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
