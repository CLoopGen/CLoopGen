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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    for (i = 0; i < height; i++) {
        // Process even indices first with stride 2
        for (j = 0; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 65535 - ((((65535 - bottom[j]) * (65535 - bottom[j])) / top[j]) > (65535) ? (65535) : (((65535 - bottom[j]) * (65535 - bottom[j])) / top[j]))) - top[j]) * opacity;
        }
        // Process odd indices in a second pass
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 65535 - ((((65535 - bottom[j]) * (65535 - bottom[j])) / top[j]) > (65535) ? (65535) : (((65535 - bottom[j]) * (65535 - bottom[j])) / top[j]))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
