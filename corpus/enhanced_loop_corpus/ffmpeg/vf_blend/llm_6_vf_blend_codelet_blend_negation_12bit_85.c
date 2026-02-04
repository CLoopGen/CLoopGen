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
            int temp_sum = top[j] + bottom[j];
            int clamped_diff = (4095 - temp_sum) >= 0 ? (4095 - temp_sum) : 0;
            int blend_value = 4095 - clamped_diff;
            dst[di + j] = top[ti + j] + (blend_value - top[ti + j]) * opacity;
        }
        di += dst_linesize;
        ti += top_linesize;
        bi += bottom_linesize;
    }
}
