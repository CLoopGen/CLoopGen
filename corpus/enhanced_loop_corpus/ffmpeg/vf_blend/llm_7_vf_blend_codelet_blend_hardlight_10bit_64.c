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
    uint16_t *dst_row, *top_row, *bottom_row;
    ptrdiff_t j_offset;
    for (i = 0; i < height; i++) {
        dst_row = dst + i * dst_linesize;
        top_row = top + i * top_linesize;
        bottom_row = bottom + i * bottom_linesize;
        for (j = 0; j < width; j++) {
            j_offset = j;
            dst_row[j_offset] = top_row[j_offset] + 
                (((bottom_row[j_offset] < 512) ? 
                    ((2) * (((bottom_row[j_offset]) * (top_row[j_offset])) / 1023)) : 
                    (1023 - (2) * ((1023 - (bottom_row[j_offset])) * (1023 - (top_row[j_offset])) / 1023))) - top_row[j_offset]) * opacity;
        }
    }
    // Eliminated pointer updates in favor of index-based addressing — removed WAW and WAR hazards on dst/top/bottom base pointers
}
