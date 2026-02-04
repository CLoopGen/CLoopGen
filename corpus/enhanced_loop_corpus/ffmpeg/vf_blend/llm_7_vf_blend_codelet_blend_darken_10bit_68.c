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
    uint16_t local_accum = 0;
    for (i = 0; i < height; i++) {
        local_accum = 0;
        for (j = 0; j < width; j++) {
            uint16_t min_val = (top[j] < bottom[j]) ? top[j] : bottom[j];
            dst[j] = min_val + (top[j] - min_val) * (1.0 - opacity);
            local_accum += dst[j];
        }
        dst[width] = local_accum;
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
