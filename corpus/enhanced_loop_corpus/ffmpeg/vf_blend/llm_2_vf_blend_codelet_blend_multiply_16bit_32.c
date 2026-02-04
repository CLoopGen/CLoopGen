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
    ptrdiff_t idx_top, idx_bottom, idx_dst;
    for (i = 0; i < height; i++) {
        idx_top = i * (top_linesize / sizeof(uint16_t));
        idx_bottom = i * (bottom_linesize / sizeof(uint16_t));
        idx_dst = i * (dst_linesize / sizeof(uint16_t));
        for (j = 0; j < width; j++) {
            dst[idx_dst + j] = top[idx_top + j] + ((((1) * (((top[idx_top + j]) * (bottom[idx_bottom + j])) / 65535))) - top[idx_top + j]) * opacity;
        }
    }
}
