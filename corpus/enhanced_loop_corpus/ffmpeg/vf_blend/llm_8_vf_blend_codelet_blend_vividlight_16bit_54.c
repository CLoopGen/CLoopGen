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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int scaled_op = (int)(opacity * 65536);
        int base = (t < 32768) ? 
            ((2 * t == 0) ? 0 : (65535 - (((65535 - b) << 16) / (2 * t + !!(2*t)))) ) :
            ((2*(t-32768) == 65535) ? 65535 : ((((b << 16) / (65535 - 2*(t-32768) + !(65535 - 2*(t-32768)))) > 65535) ? 65535 : ((b << 16) / (65535 - 2*(t-32768) + !(65535 - 2*(t-32768))))));
        dst[j] = t + ((base - t) * scaled_op >> 16);
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
    if (i + 1 < height) {
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
}
