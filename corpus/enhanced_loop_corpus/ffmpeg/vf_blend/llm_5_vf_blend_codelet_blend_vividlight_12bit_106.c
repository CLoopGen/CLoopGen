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
        int twice_t = 2 * t;
        int base_val;

        if (t < 2048 && twice_t != 0) {
            int numerator = (4095 - b) << 12;
            int result = 4095 - (numerator / twice_t);
            base_val = result < 0 ? 0 : result;
        } else if (t < 2048) {
            base_val = 0;
        } else {
            int shifted = 2 * (t - 2048);
            if (shifted >= 4095) {
                base_val = 4095;
            } else {
                int denom = 4095 - shifted;
                int temp = (b << 12) / denom;
                base_val = temp < 4095 ? temp : 4095;
            }
        }

        dst[j] = t + (base_val - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
