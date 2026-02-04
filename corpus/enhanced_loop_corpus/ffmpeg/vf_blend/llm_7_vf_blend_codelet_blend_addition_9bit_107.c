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
    ptrdiff_t top_offset = 0, bottom_offset = 0, dst_offset = 0;
    for (i = 0; i < height; i++) {
        top_offset = i * top_linesize;
        bottom_offset = i * bottom_linesize;
        dst_offset = i * dst_linesize;
        for (j = 0; j < width; j++) {
            top_j = &top[top_offset + j];
            bottom_j = &bottom[bottom_offset + j];
            dst_j = &dst[dst_offset + j];
            *dst_j = *top_j + ((((511) > (*top_j + *bottom_j)) ? (*top_j + *bottom_j) : (511)) - *top_j) * opacity;
        }
    }
}
