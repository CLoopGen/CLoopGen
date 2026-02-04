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
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        uint32_t comp = (t_val == 1023) ? t_val : ((b_val << 10) / (1023 - t_val));
        uint32_t limited = comp < 1023 ? comp : 1023;
        int32_t diff = limited - t_val;
        double factor = opacity * diff;

        dst[j] = t_val + (uint16_t)factor;

        if (i + 1 < height) {
            uint16_t t_next = *(top + top_linesize + j);
            uint16_t b_next = *(bottom + bottom_linesize + j);
            uint32_t comp_next = (t_next == 1023) ? t_next : ((b_next << 10) / (1023 - t_next));
            uint32_t limited_next = comp_next < 1023 ? comp_next : 1023;
            int32_t diff_next = limited_next - t_next;
            double factor_next = opacity * diff_next;
            *(dst + dst_linesize + j) = t_next + (uint16_t)factor_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
