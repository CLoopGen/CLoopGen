#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *dst_j, *top_j, *bottom_j;
    for (i = 0; i < height; i++) {
        dst_j = dst;
        top_j = top;
        bottom_j = bottom;
        for (j = 0; j < width; j++) {
            *dst_j = *top_j + (((*top_j + *bottom_j) / 2) - *top_j) * opacity;
            dst_j++;
            top_j++;
            bottom_j++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
