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
ptrdiff_t t_off = top_linesize;
ptrdiff_t b_off = bottom_linesize;
ptrdiff_t d_off = dst_linesize;
double op = opacity;

for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint16_t inv_bottom = 4095 - bottom_row[j];
        uint32_t term = (top_row[j] == 0) ? 0 : (inv_bottom * inv_bottom) / top_row[j];
        uint16_t blend = (term > 4095) ? 4095 : term;
        dst_row[j] = top_row[j] + ((top_row[j] - (4095 - blend)) * op);
    }
    top_row += t_off;
    bottom_row += b_off;
    dst_row += d_off;
}
}
