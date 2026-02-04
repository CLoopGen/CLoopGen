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
        int adjusted = (t < 256) ? 
            ((2 * t) == 0 ? (2 * t) : (0 > (511 - ((511 - b) << 9) / (2 * t)) ? 0 : (511 - ((511 - b) << 9) / (2 * t))))
            : ((2 * (t - 256)) == 511 ? (2 * (t - 256)) : (511 > ((b << 9) / (511 - (2 * (t - 256)))) ? ((b << 9) / (511 - (2 * (t - 256)))) : 511));
        dst[j] = t + (adjusted - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
