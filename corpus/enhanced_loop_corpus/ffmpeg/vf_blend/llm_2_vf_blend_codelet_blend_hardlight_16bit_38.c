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
    ptrdiff_t top_offset = 0;
    ptrdiff_t bottom_offset = 0;
    ptrdiff_t dst_offset = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ptrdiff_t idx = j;
            dst[dst_offset + idx] = top[top_offset + idx] + 
                (((bottom[bottom_offset + idx] < 32768) ? 
                    ((2) * (((bottom[bottom_offset + idx]) * (top[top_offset + idx])) / 65535)) : 
                    (65535 - (2) * ((65535 - (bottom[bottom_offset + idx])) * (65535 - (top[top_offset + idx])) / 65535))) - 
                 top[top_offset + idx]) * opacity;
        }
        dst_offset += dst_linesize;
        top_offset += top_linesize;
        bottom_offset += bottom_linesize;
    }
}
