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
        uint16_t *dst_row = dst;
        uint16_t *top_row = top;
        uint16_t *bottom_row = bottom;
        for (j = 0; j < local_width; j++) {
            uint16_t top_val = top_row[j];
            uint16_t bottom_val = bottom_row[j];
            uint16_t blended;

            if (top_val == 511) {
                blended = 511;
            } else {
                ptrdiff_t temp = (bottom_val << 9) / (511 - top_val);
                blended = (temp > 511) ? 511 : temp;
            }

            dst_row[j] = top_val + (blended - top_val) * local_opacity;
        }
        dst += local_dst_linesize;
        top += local_top_linesize;
        bottom += local_bottom_linesize;
    }
}
