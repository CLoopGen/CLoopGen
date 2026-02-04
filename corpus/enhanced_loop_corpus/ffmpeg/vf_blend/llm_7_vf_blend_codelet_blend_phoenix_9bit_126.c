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
ptrdiff_t t_ls = top_linesize;
ptrdiff_t b_ls = bottom_linesize;
ptrdiff_t d_ls = dst_linesize;
int h = height;
int w = width;
double op = opacity;

for (i = 0; i < h; i++) {
    for (j = 0; j < w; j++) {
        uint16_t min_val = (top_row[j]) < (bottom_row[j]) ? top_row[j] : bottom_row[j];
        uint16_t max_val = (top_row[j]) < (bottom_row[j]) ? bottom_row[j] : top_row[j];
        dst_row[j] = min_val + ((min_val - max_val + 511) - min_val) * op;
    }
    dst_row += d_ls;
    top_row += t_ls;
    bottom_row += b_ls;
}
}
