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
    ptrdiff_t local_top_inc = top_linesize;
    ptrdiff_t local_bottom_inc = bottom_linesize;
    ptrdiff_t local_dst_inc = dst_linesize;
    for (j = 0; j < width; j++) {
        uint16_t t_val = top[j];
        uint16_t b_val = bottom[j];
        int32_t diff = 4095 - t_val - b_val;
        uint16_t clamped_diff = (diff >= 4095) ? 4095 : ((diff < 0) ? 0 : diff);
        uint16_t result = t_val + ((4095 - clamped_diff) - t_val) * opacity;
        dst[j] = result;

        if (i + 1 < height) {
            uint16_t t_next = *(top + local_top_inc + j);
            uint16_t b_next = *(bottom + local_bottom_inc + j);
            int32_t diff_next = 4095 - t_next - b_next;
            uint16_t clamped_diff_next = (diff_next >= 4095) ? 4095 : ((diff_next < 0) ? 0 : diff_next);
            uint16_t result_next = t_next + ((4095 - clamped_diff_next) - t_next) * opacity;
            *(dst + local_dst_inc + j) = result_next;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
