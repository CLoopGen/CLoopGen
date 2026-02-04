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
        if (i < height) {
            uint16_t t = top[j];
            uint16_t b = bottom[j];
            dst[j] = (t == 1023) ? t : t + (((b * b / (1023 - t)) > 1023 ? 1023 : (b * b / (1023 - t))) - t) * opacity;
        }

        if (i + 1 < height) {
            uint16_t t_next = top[top_linesize + j];
            uint16_t b_next = bottom[bottom_linesize + j];
            uint16_t result = (t_next == 1023) ? t_next : t_next + (((b_next * b_next / (1023 - t_next)) > 1023 ? 1023 : (b_next * b_next / (1023 - t_next))) - t_next) * opacity;
            dst[dst_linesize + j] = result;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
