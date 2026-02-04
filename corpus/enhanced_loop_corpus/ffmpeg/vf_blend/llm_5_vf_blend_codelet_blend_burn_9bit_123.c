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
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int computed = 0;
        if (t != 0) {
            int intermediate = (511 - ((511 - b) << 9) / t);
            if (intermediate > 0) {
                computed = intermediate;
            }
        }
        dst[j] = t + ((computed - t) * opacity);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
