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
    ptrdiff_t local_dst_offset = 0;
    ptrdiff_t local_top_offset = 0;
    ptrdiff_t local_bot_offset = 0;
    uint16_t *local_dst_base = dst;
    uint16_t *local_top_base = top;
    uint16_t *local_bottom_base = bottom;
    double local_opacity = opacity;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = j;
            int32_t temp_sum = local_top_base[local_top_offset + idx] + local_bottom_base[local_bot_offset + idx];
            int32_t clamped_diff = 1023 - temp_sum;
            int32_t abs_val = (clamped_diff >= 0) ? clamped_diff : -clamped_diff;
            int32_t blended = local_top_base[local_top_offset + idx] + 
                             (abs_val - local_top_base[local_top_offset + idx]) * local_opacity;
            local_dst_base[local_dst_offset + idx] = (uint16_t)blended;
        }
        local_dst_offset += dst_linesize;
        local_top_offset += top_linesize;
        local_bot_offset += bottom_linesize;
    }
}
