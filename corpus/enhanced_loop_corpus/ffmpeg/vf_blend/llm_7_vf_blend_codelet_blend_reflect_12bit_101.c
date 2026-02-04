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
uint16_t prev_top_j = 0, prev_bottom_j = 0;
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t current_top = (j == 0) ? top[j] : (top[j] + prev_top_j) / 2;
        uint16_t current_bottom = (j == 0) ? bottom[j] : (bottom[j] + prev_bottom_j) / 2;
        prev_top_j = top[j];
        prev_bottom_j = bottom[j];

        uint16_t computed = (current_bottom == 4095) ? 4095 : (current_top * current_top);
        if (current_bottom < 4095) {
            computed /= (4095 - current_bottom);
            if (computed > 4095) computed = 4095;
        }

        dst[j] = current_top + (computed - current_top) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
