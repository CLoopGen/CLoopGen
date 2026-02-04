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
            int k = j;
            int k_next = j + 1;
            if (k < width) {
                dst[k] = top[k] + (((bottom[k] == 1023) ? bottom[k] : ((1023) > ((top[k] * top[k] / (1023 - bottom[k]))) ? ((top[k] * top[k] / (1023 - bottom[k]))) : (1023))) - top[k]) * opacity;
            }
            if (k_next < width) {
                dst[k_next] = top[k_next] + (((bottom[k_next] == 1023) ? bottom[k_next] : ((1023) > ((top[k_next] * top[k_next] / (1023 - bottom[k_next]))) ? ((top[k_next] * top[k_next] / (1023 - bottom[k_next]))) : (1023))) - top[k_next]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
