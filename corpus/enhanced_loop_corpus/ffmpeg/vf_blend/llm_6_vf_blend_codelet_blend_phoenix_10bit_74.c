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
    ptrdiff_t local_width = width;
    ptrdiff_t local_height = height;
    double local_opacity = opacity;
    for (i = 0; i < local_height; i++) {
        uint16_t *top_row = top + i * top_linesize;
        uint16_t *bottom_row = bottom + i * bottom_linesize;
        uint16_t *dst_row = dst + i * dst_linesize;
        for (j = 0; j < local_width; j++) {
            uint16_t t_val = top_row[j];
            uint16_t b_val = bottom_row[j];
            uint16_t min_val = (t_val > b_val) ? b_val : t_val;
            uint16_t max_val = (t_val > b_val) ? t_val : b_val;
            int32_t diff_adj = (max_val - min_val + 1023) - t_val;
            dst_row[j] = t_val + (diff_adj * local_opacity);
        }
    }
}
