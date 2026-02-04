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

    for (i = 0; i < local_height; i++) {
        uint16_t *top_row = top;
        uint16_t *bottom_row = bottom;
        uint16_t *dst_row = dst;

        for (j = 0; j < local_width; j++) {
            uint16_t top_val = top_row[j];
            uint16_t bottom_val = bottom_row[j];
            uint16_t inverted_top = 1023 - top_val;
            uint32_t numerator = (uint32_t)inverted_top * inverted_top;
            uint16_t blend_val = 0;

            if (bottom_val != 0) {
                uint32_t div_result = numerator / bottom_val;
                blend_val = (div_result > 1023) ? 1023 : (uint16_t)div_result;
            }

            uint16_t result_component = top_val + ((1023 - blend_val) - top_val) * local_opacity;
            dst_row[j] = result_component;
        }

        dst += local_dst_linesize;
        top += local_top_linesize;
        bottom += local_bottom_linesize;
    }
}
