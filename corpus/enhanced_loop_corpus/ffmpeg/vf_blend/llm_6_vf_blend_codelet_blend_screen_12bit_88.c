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
    ptrdiff_t di, ti, bi;
    for (i = 0; i < height; i++) {
        di = i * dst_linesize;
        ti = i * top_linesize;
        bi = i * bottom_linesize;
        for (j = 0; j < width; j++) {
            ptrdiff_t dj = di + j;
            ptrdiff_t tj = ti + j;
            ptrdiff_t bj = bi + j;
            uint16_t t_val = top[tj];
            uint16_t b_val = bottom[bj];
            int intermediate = (4095 - t_val) * (4095 - b_val) / 4095;
            int blended = 4095 - intermediate;
            dst[dj] = t_val + (blended - t_val) * opacity;
        }
    }
}
