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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t *top_i, *bottom_i, *dst_i;
    ptrdiff_t ti = 0, bi = 0, di = 0;
    for (i = 0; i < height; i++) {
        top_i = top + ti;
        bottom_i = bottom + bi;
        dst_i = dst + di;
        for (j = 0; j < width; j++) {
            dst_i[j] = (uint16_t)(top_i[j] * opacity + bottom_i[j] * (1. - opacity) + 0.5);
        }
        ti += top_linesize;
        bi += bottom_linesize;
        di += dst_linesize;
    }
}
