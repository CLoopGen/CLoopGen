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
    ptrdiff_t offset;
    for (i = 0; i < height; i++) {
        offset = i * dst_linesize / sizeof(uint16_t);
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = offset + j;
            ((uint16_t*)dst)[idx] = ((uint16_t*)top)[idx] + (((((uint16_t*)bottom)[idx] == 1023) ? (((uint16_t*)bottom)[idx]) : ((1023) > ((((uint16_t*)top)[idx] * ((uint16_t*)top)[idx] / (1023 - ((uint16_t*)bottom)[idx]))) ? ((((uint16_t*)top)[idx] * ((uint16_t*)top)[idx] / (1023 - ((uint16_t*)bottom)[idx]))) : (1023))) - ((uint16_t*)top)[idx]) * opacity;
        }
    }
    dst += height * dst_linesize;
    top += height * top_linesize;
    bottom += height * bottom_linesize;
}
