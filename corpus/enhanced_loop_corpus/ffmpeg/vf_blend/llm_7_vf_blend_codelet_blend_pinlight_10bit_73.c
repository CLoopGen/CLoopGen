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
    dst_row = dst + i * (dst_linesize / sizeof(uint16_t));
    top_row = top + i * (top_linesize / sizeof(uint16_t));
    bottom_row = bottom + i * (bottom_linesize / sizeof(uint16_t));
    for (j = 0; j < width; j++) {
        uint16_t base = top_row[j];
        uint16_t contrib = (bottom_row[j] < 512) ?
            (base > 2 * bottom_row[j] ? 2 * bottom_row[j] : base) :
            (base > 2 * (bottom_row[j] - 512) ? base : 2 * (bottom_row[j] - 512));
        dst_row[j] = base + (contrib - base) * opacity;
    }
}
}
