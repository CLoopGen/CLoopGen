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
    uint16_t *top_j, *bottom_j, *dst_j;
    ptrdiff_t offset;
    for (i = 0; i < height; i++) {
        offset = i * dst_linesize / sizeof(uint16_t);
        for (j = 0; j < width; j++) {
            top_j = &top[i * top_linesize / sizeof(uint16_t) + j];
            bottom_j = &bottom[i * bottom_linesize / sizeof(uint16_t) + j];
            dst_j = &dst[offset + j];
            dst_j[0] = top_j[0] + ((((0) > (top_j[0] - bottom_j[0]) ? (0) : (top_j[0] - bottom_j[0]))) - top_j[0]) * opacity;
        }
    }
}
