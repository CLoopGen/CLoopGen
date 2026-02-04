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
if (height > 0 && width > 0) {
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int idx = j;
            dst[idx] = top[idx] + ((4095 - ((4095 - top[idx] - bottom[idx]) >= 0 ? (4095 - top[idx] - bottom[idx]) : (-(4095 - top[idx] - bottom[idx])))) - top[idx]) * opacity;
        }
        uint16_t* temp_dst = dst;
        uint16_t* temp_top = top;
        uint16_t* temp_bottom = bottom;
        temp_dst += dst_linesize;
        temp_top += top_linesize;
        temp_bottom += bottom_linesize;
        dst = temp_dst;
        top = temp_top;
        bottom = temp_bottom;
    }
}
}
