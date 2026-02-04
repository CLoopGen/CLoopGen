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
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                dst[j] = top[j] + (((top[j] == 1023) ? top[j] : ((1023) > ((bottom[j] * bottom[j] / (1023 - top[j]))) ? ((bottom[j] * bottom[j] / (1023 - top[j]))) : (1023))) - top[j]) * opacity;
                dst[j+1] = top[j+1] + (((top[j+1] == 1023) ? top[j+1] : ((1023) > ((bottom[j+1] * bottom[j+1] / (1023 - top[j+1]))) ? ((bottom[j+1] * bottom[j+1] / (1023 - top[j+1]))) : (1023))) - top[j+1]) * opacity;
            } else {
                dst[j] = top[j] + (((top[j] == 1023) ? top[j] : ((1023) > ((bottom[j] * bottom[j] / (1023 - top[j]))) ? ((bottom[j] * bottom[j] / (1023 - top[j]))) : (1023))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
