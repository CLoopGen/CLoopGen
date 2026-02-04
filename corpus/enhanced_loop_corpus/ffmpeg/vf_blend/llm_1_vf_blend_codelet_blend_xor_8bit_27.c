#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint8_t t_val = top[j];
        uint8_t b_val = bottom[j];
        dst[j] = t_val + ((t_val ^ b_val) - t_val) * opacity;
    }
    uint8_t* dst_temp = dst;
    uint8_t* top_temp = top;
    uint8_t* bottom_temp = bottom;
    dst = dst_temp + dst_linesize;
    top = top_temp + top_linesize;
    bottom = bottom_temp + bottom_linesize;
}
}
