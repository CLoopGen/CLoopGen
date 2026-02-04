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
        uint16_t top_val = top[j];
        uint16_t bottom_val = bottom[j];
        int adjusted_top = 2 * top_val;
        int base;

        if (top_val < 256) {
            if (adjusted_top == 0) {
                base = 0;
            } else {
                int temp = (511 - ((511 - bottom_val) << 9) / adjusted_top);
                base = (temp < 0) ? 0 : (temp > 511 ? 511 : temp);
            }
        } else {
            int shifted_top = 2 * (top_val - 256);
            if (shifted_top == 511) {
                base = 511;
            } else {
                int denom = 511 - shifted_top;
                int temp = (bottom_val << 9) / denom;
                base = (temp < 511) ? temp : 511;
            }
        }
        dst[j] = top_val + (base - top_val) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
