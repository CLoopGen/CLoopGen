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
    ptrdiff_t j_scaled;
    for (i = 0; i < height; i++) {
        dst_row = dst;
        top_row = top;
        bottom_row = bottom;
        for (j = 0; j < width; j++) {
            j_scaled = j * sizeof(uint16_t);
            dst_row[j] = top_row[j] + (((top_row[j] < 32768) ? 
                ((2) * (((top_row[j]) * (bottom_row[j])) / 65535)) : 
                (65535 - (2) * ((65535 - (top_row[j])) * (65535 - (bottom_row[j])) / 65535))) - top_row[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
