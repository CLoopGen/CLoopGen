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
    uint16_t local_top, local_bottom;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            local_top = top[j];
            local_bottom = bottom[j];
            dst[j] = local_top + ((((local_top) > (local_bottom) ? (local_top) : (local_bottom))) - local_top) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
