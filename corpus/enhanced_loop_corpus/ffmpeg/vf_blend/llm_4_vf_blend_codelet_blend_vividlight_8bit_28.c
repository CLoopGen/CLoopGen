#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint8_t top_val = top[j];
        uint8_t bottom_val = bottom[j];
        int base;
        if (top_val < 128) {
            int temp = 2 * top_val;
            base = (temp == 0) ? 0 : (0 > (255 - ((255 - bottom_val) << 8) / temp) ? 0 : (255 - ((255 - bottom_val) << 8) / temp));
        } else {
            int adjusted = 2 * (top_val - 128);
            int denominator = 255 - adjusted;
            base = (adjusted == 255) ? 255 : (255 > ((bottom_val << 8) / (denominator == 0 ? 1 : denominator)) ? ((bottom_val << 8) / (denominator == 0 ? 1 : denominator)) : 255);
        }
        dst[j] = top_val + (base - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
