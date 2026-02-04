#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t local_top, local_bottom, min_val;
    uint8_t *dst_row = dst;
    uint8_t *top_row = top;
    uint8_t *bottom_row = bottom;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            local_top = top_row[j];
            local_bottom = bottom_row[j];
            min_val = (local_bottom < local_top) ? local_bottom : local_top;
            dst_row[j] = local_top + (min_val - local_top) * opacity;
        }
        dst_row += dst_linesize;
        top_row += top_linesize;
        bottom_row += bottom_linesize;
    }
}
