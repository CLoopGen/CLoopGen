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
        int val1 = (top[j] == 0) ? 0 : (((511 - bottom[j]) * (511 - bottom[j])) / top[j]);
        int clamped_val1 = (val1 > 511) ? 511 : val1;
        dst[j] = top[j] + (clamped_val1 - top[j]) * opacity;

        if (j + 1 < width) {
            int val2 = (top[j+1] == 0) ? 0 : (((511 - bottom[j+1]) * (511 - bottom[j+1])) / top[j+1]);
            int clamped_val2 = (val2 > 511) ? 511 : val2;
            dst[j+1] = top[j+1] + (clamped_val2 - top[j+1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
