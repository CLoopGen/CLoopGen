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
uint16_t *top_row = top;
uint16_t *bottom_row = bottom;
uint16_t *dst_row = dst;
ptrdiff_t t_stride = top_linesize;
ptrdiff_t b_stride = bottom_linesize;
ptrdiff_t d_stride = dst_linesize;

for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t min_val = (top_row[j] < bottom_row[j]) ? top_row[j] : bottom_row[j];
        uint16_t max_val = (top_row[j] > bottom_row[j]) ? top_row[j] : bottom_row[j];
        dst_row[j] = min_val + (4095 - max_val) * opacity;
    }
    top_row += t_stride;
    bottom_row += b_stride;
    dst_row += d_stride;
}
}
