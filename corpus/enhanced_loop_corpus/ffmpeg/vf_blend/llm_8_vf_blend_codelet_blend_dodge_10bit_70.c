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
        uint16_t top_val1 = top[j];
        uint16_t bot_val1 = bottom[j];
        uint16_t top_val2 = top[j+1];
        uint16_t bot_val2 = bottom[j+1];
        
        uint32_t scaled_diff1 = (top_val1 == 1023) ? 0 : ((bot_val1 << 10) / (1023 - top_val1));
        uint32_t clamped1 = (scaled_diff1 > 1023) ? 1023 : scaled_diff1;
        dst[j] = top_val1 + (uint16_t)((clamped1 - top_val1) * opacity);

        if (j + 1 < width) {
            uint32_t scaled_diff2 = (top_val2 == 1023) ? 0 : ((bot_val2 << 10) / (1023 - top_val2));
            uint32_t clamped2 = (scaled_diff2 > 1023) ? 1023 : scaled_diff2;
            dst[j+1] = top_val2 + (uint16_t)((clamped2 - top_val2) * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
