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
    ptrdiff_t tj = 0, bj = 0, dj = 0;
    for (j = 0; j < width; j += 4) {
        for (int k = 0; k < 4 && (j + k) < width; k++) {
            uint16_t t_val = top[tj + k];
            uint16_t b_val = bottom[bj + k];
            uint16_t result;
            if (b_val < 2048) {
                result = (2 * ((b_val * t_val) / 4095));
            } else {
                result = 4095 - (2 * ((4095 - b_val) * (4095 - t_val) / 4095));
            }
            dst[dj + k] = t_val + (int16_t)((result - t_val) * opacity);
        }
        tj += 4; bj += 4; dj += 4;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
