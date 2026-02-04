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
    for (j = 0; j < width; j++) {
        uint16_t temp_val;
        int cond1 = bottom[j] < 512;
        int cond2 = top[j] > 2 * (cond1 ? bottom[j] : (bottom[j] - 512));
        temp_val = cond1 ? 
                   (cond2 ? 2 * bottom[j] : top[j]) : 
                   (cond2 ? top[j] : 2 * (bottom[j] - 512));
        dst[j] = top[j] + (temp_val - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
