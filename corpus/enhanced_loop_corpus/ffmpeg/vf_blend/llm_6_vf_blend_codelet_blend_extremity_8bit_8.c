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
    uint8_t temp;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = top[j];
            dst[j] = temp + ((((255 - temp - bottom[j]) >= 0 ? (255 - temp - bottom[j]) : (-(255 - temp - bottom[j])))) - temp) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
