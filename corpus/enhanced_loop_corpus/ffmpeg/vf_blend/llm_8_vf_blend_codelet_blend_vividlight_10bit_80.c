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
        int scaled_opacity = (int)(opacity * 1024);
        int base = (t < 512) ? 
            ((2 * t) == 0 ? 0 : (0 > (1023 - ((1023 - b) << 10) / (2 * t)) ? 0 : (1023 - ((1023 - b) << 10) / (2 * t))))
            : ((2 * (t - 512)) == 1023 ? 1023 : (1023 > ((b << 10) / (1023 - 2*(t-512))) ? ((b << 10) / (1023 - 2*(t-512))) : 1023));
        dst[j] = t + ((base - t) * scaled_opacity >> 10);
    }
    for (j = 0; j < width; j++) {
        uint16_t t = top[j];
        uint16_t b = bottom[j];
        int scaled_opacity = (int)(opacity * 1024);
        int base = (t < 512) ? 
            ((2 * t) == 0 ? 0 : (0 > (1023 - ((1023 - b) << 10) / (2 * t)) ? 0 : (1023 - ((1023 - b) << 10) / (2 * t))))
            : ((2 * (t - 512)) == 1023 ? 1023 : (1023 > ((b << 10) / (1023 - 2*(t-512))) ? ((b << 10) / (1023 - 2*(t-512))) : 1023));
        dst[width + j] = t + ((base - t) * scaled_opacity >> 10);
    }
    dst += dst_linesize * 2;
    top += top_linesize * 2;
    bottom += bottom_linesize * 2;
}
}
