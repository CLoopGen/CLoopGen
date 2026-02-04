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
        int is_low = (t < 2048);
        int base_val;
        if (is_low) {
            int twice_t = 2 * t;
            if (twice_t == 0) {
                base_val = 0;
            } else {
                int temp = (4095 - b) << 12;
                int div = temp / twice_t;
                base_val = (0 > (4095 - div)) ? 0 : (4095 - div);
            }
        } else {
            int shifted_t = 2 * (t - 2048);
            if (shifted_t == 4095) {
                base_val = 4095;
            } else {
                int denom = 4095 - shifted_t;
                int temp = (b << 12) / denom;
                base_val = (4095 > temp) ? temp : 4095;
            }
        }
        dst[j] = t + (base_val - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
