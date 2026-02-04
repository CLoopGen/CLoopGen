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
        uint16_t t1 = top[j];
        uint16_t b1 = bottom[j];
        uint32_t diff1 = 65535 - t1;
        uint32_t div1 = (b1 == 0) ? 0 : (diff1 * diff1) / b1;
        uint32_t val1 = (div1 > 65535) ? 65535 : div1;
        dst[j] = t1 + ((val1 - t1) * opacity);

        if (j + 1 < width) {
            uint16_t t2 = top[j+1];
            uint16_t b2 = bottom[j+1];
            uint32_t diff2 = 65535 - t2;
            uint32_t div2 = (b2 == 0) ? 0 : (diff2 * diff2) / b2;
            uint32_t val2 = (div2 > 65535) ? 65535 : div2;
            dst[j+1] = t2 + ((val2 - t2) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
