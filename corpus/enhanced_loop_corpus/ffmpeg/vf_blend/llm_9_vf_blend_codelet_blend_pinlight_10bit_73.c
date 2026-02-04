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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        uint16_t result1, result2;

        // First row: i
        uint16_t t1 = top[j];
        uint16_t b1 = bottom[j];
        uint16_t adjusted1 = (b1 < 512) ? 
            (t1 > 2*b1 ? 2*b1 : t1) : 
            (t1 > 2*(b1 - 512) ? t1 : 2*(b1 - 512));
        result1 = t1 + (adjusted1 - t1) * opacity;

        // Second row: i+1 (if valid)
        if (i + 1 < height) {
            uint16_t t2 = top[j] + top_linesize;
            uint16_t b2 = bottom[j] + bottom_linesize;
            uint16_t adjusted2 = (b2 < 512) ? 
                (t2 > 2*b2 ? 2*b2 : t2) : 
                (t2 > 2*(b2 - 512) ? t2 : 2*(b2 - 512));
            result2 = t2 + (adjusted2 - t2) * opacity;

            dst[dst_linesize + j] = result2;
        }

        dst[j] = result1;
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
