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
    uint16_t *dst_offset, *top_offset, *bottom_offset;
    ptrdiff_t j_scaled;
    for (i = 0; i < height; i++) {
        dst_offset = dst + i * dst_linesize;
        top_offset = top + i * top_linesize;
        bottom_offset = bottom + i * bottom_linesize;
        for (j = 0; j < width; j++) {
            j_scaled = j;
            dst_offset[j_scaled] = top_offset[j_scaled] + 
                (((bottom_offset[j_scaled] < 256) ? 
                    ((2) * (((bottom_offset[j_scaled]) * (top_offset[j_scaled])) / 511)) : 
                    (511 - (2) * ((511 - (bottom_offset[j_scaled])) * (511 - (top_offset[j_scaled])) / 511))) - top_offset[j_scaled]) * opacity;
        }
    }
}
