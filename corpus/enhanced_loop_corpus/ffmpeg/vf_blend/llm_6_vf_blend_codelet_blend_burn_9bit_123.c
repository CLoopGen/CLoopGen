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
    ptrdiff_t di = 0, ti = 0, bi = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int temp_top = top[ti + j];
            int temp_bottom = bottom[bi + j];
            int adjusted = (temp_top == 0) ? temp_top : 
                          ((0 > (511 - ((511 - temp_bottom) << 9) / temp_top)) ? 0 : 
                           (511 - ((511 - temp_bottom) << 9) / temp_top));
            dst[di + j] = temp_top + ((adjusted - temp_top) * opacity);
        }
        di += dst_linesize;
        ti += top_linesize;
        bi += bottom_linesize;
    }
}
