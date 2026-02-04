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
    for (i = 0; i < height; i++) {
        uint16_t *top_ptr = top_row;
        uint16_t *bottom_ptr = bottom_row;
        uint16_t *dst_ptr = dst_row;
        for (j = 0; j < width; j++) {
            *dst_ptr = *top_ptr + ((511 - ((511 - *top_ptr - *bottom_ptr) >= 0 ? (511 - *top_ptr - *bottom_ptr) : (-(511 - *top_ptr - *bottom_ptr)))) - *top_ptr) * opacity;
            top_ptr++;
            bottom_ptr++;
            dst_ptr++;
        }
        top_row += top_linesize;
        bottom_row += bottom_linesize;
        dst_row += dst_linesize;
    }
}
