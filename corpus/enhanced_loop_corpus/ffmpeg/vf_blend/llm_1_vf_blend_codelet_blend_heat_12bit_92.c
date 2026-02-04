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
            uint16_t t = top[j];
            uint16_t b = bottom[j];
            int term = (t == 0) ? 0 : 4095 - (((((4095 - b) * (4095 - b)) / t) > 4095) ? 4095 : (((4095 - b) * (4095 - b)) / t));
            dst[j] = t + (term - t) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
} else {
    return;
}
}
