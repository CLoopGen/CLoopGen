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
    ptrdiff_t local_dst_linesize = dst_linesize;
    ptrdiff_t local_top_linesize = top_linesize;
    ptrdiff_t local_bottom_linesize = bottom_linesize;
    ptrdiff_t local_width = width;
    ptrdiff_t local_height = height;
    double local_opacity = opacity;
    uint16_t *local_dst = dst;
    uint16_t *local_top = top;
    uint16_t *local_bottom = bottom;

    for (i = 0; i < local_height; i++) {
        uint16_t *row_dst = local_dst;
        uint16_t *row_top = local_top;
        uint16_t *row_bottom = local_bottom;
        for (j = 0; j < local_width; j++) {
            uint16_t t_val = row_top[j];
            uint16_t b_val = row_bottom[j];
            int32_t diff = 65535 - t_val - b_val;
            uint16_t clamped_diff = (diff >= 0) ? diff : -diff;
            uint16_t blended = 65535 - clamped_diff;
            row_dst[j] = t_val + (blended - t_val) * local_opacity;
        }
        local_dst += local_dst_linesize;
        local_top += local_top_linesize;
        local_bottom += local_bottom_linesize;
    }
}
