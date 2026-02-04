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
    for (i = 0; i < height; i++) {
        dst_row = (uint16_t*)((char*)dst + i * dst_linesize);
        top_row = (uint16_t*)((char*)top + i * top_linesize);
        bottom_row = (uint16_t*)((char*)bottom + i * bottom_linesize);
        for (j = 0; j < width; j += 2) {
            if (j + 1 < width) {
                dst_row[j]     = top_row[j] + ((((1) * (((top_row[j]) * (bottom_row[j])) / 65535))) - top_row[j]) * opacity;
                dst_row[j + 1] = top_row[j + 1] + ((((1) * (((top_row[j + 1]) * (bottom_row[j + 1])) / 65535))) - top_row[j + 1]) * opacity;
            } else {
                dst_row[j] = top_row[j] + ((((1) * (((top_row[j]) * (bottom_row[j])) / 65535))) - top_row[j]) * opacity;
            }
        }
    }
}
