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
    ptrdiff_t di = 0;
    ptrdiff_t ti = 0;
    ptrdiff_t bi = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            uint16_t t_val = top[ti + j];
            uint16_t b_val = bottom[bi + j];
            int temp = 511 - t_val - b_val;
            int clamped = (temp >= 0) ? temp : (-temp);
            int mixed = t_val + (511 - clamped) - t_val;
            dst[di + j] = t_val + mixed * opacity;
        }
        di += dst_linesize;
        ti += top_linesize;
        bi += bottom_linesize;
    }
}
