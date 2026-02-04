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
    j = 0;
    if (width > 0) {
        do {
            dst[j] = top[j] + (((top[j] == 0) ? 0 : 511 - ((((511 - bottom[j]) * (511 - bottom[j])) / top[j]) > (511) ? (511) : (((511 - bottom[j]) * (511 - bottom[j])) / top[j]))) - top[j]) * opacity;
            j++;
        } while (j < width);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
