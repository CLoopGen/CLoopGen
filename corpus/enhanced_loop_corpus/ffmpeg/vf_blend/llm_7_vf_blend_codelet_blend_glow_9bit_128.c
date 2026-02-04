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
    ptrdiff_t di, dj;
    uint16_t combined;
    for (di = 0; di < height; di++) {
        for (dj = 0; dj < width; dj++) {
            combined = (top[dj] + bottom[dj]) >> 1;
            if (combined > 511) combined = 511;
            dst[dj] = top[dj] + (((top[dj] == 511) ? top[dj] : ((combined) > ((bottom[dj] * bottom[dj] / (511 - top[dj]))) ? ((bottom[dj] * bottom[dj] / (511 - top[dj]))) : (combined))) - top[dj]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
