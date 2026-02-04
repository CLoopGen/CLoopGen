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
ptrdiff_t t_line = top_linesize;
ptrdiff_t b_line = bottom_linesize;
ptrdiff_t d_line = dst_linesize;
double opac = opacity;
int w = width;
int h = height;

for (i = 0; i < h; i++) {
    uint16_t prev_dst = 0;
    for (j = 0; j < w; j++) {
        int base = top_row[j];
        int source = bottom_row[j];
        int selection = (base == 0) ? base : (4095 - ((4095 - source) << 12) / base);
        int bounded = (selection < 0) ? 0 : (selection > 4095) ? 4095 : selection;
        int contribution = (bounded - base) * opac;
        dst_row[j] = base + contribution + (prev_dst >> 4); // Introduce RAW dependency: current output depends on previous output
        prev_dst = dst_row[j];
    }
    top_row += t_line;
    bottom_row += b_line;
    dst_row += d_line;
}
}
