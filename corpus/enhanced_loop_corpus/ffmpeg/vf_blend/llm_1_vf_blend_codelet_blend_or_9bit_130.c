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
    for (i = 0; i < height * width; i++) {
        int idx = i % width;
        int offset_top = (i / width) * (top_linesize / sizeof(uint16_t));
        int offset_bottom = (i / width) * (bottom_linesize / sizeof(uint16_t));
        int offset_dst = (i / width) * (dst_linesize / sizeof(uint16_t));
        dst[offset_dst + idx] = top[offset_top + idx] + 
                                ((top[offset_top + idx] | bottom[offset_bottom + idx]) - top[offset_top + idx]) * opacity;
    }
}
