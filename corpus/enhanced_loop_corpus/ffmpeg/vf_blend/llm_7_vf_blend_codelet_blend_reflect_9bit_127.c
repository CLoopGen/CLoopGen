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
uint16_t *dst_row = dst;
const ptrdiff_t tl = top_linesize;
const ptrdiff_t bl = bottom_linesize;
const ptrdiff_t dl = dst_linesize;
const int w = width;
const int h = height;
uint16_t *top_row = top;
uint16_t *bottom_row = bottom;

for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
        uint16_t computed = (bottom_row[j] == 511) ? 511 : ((511) > ((top_row[j] * top_row[j]) / (511U - bottom_row[j])) ? ((top_row[j] * top_row[j]) / (511U - bottom_row[j])) : 511);
        dst_row[j] = (uint16_t)(top_row[j] + (computed - top_row[j]) * opacity);
    }
    dst_row += dl;
    top_row += tl;
    bottom_row += bl;
}
}
