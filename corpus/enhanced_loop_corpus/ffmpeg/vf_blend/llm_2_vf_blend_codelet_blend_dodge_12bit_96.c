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
for (i = 0; i < height; i++) {
    ptrdiff_t dst_idx = i * dst_linesize;
    ptrdiff_t top_idx = i * top_linesize;
    ptrdiff_t bot_idx = i * bottom_linesize;
    for (j = 0; j < width; j++) {
        ptrdiff_t idx = dst_idx + j;
        ptrdiff_t t_idx = top_idx + j;
        ptrdiff_t b_idx = bot_idx + j;
        dst[idx] = top[t_idx] + (((((top[t_idx]) == 4095) ? (top[t_idx]) : ((4095) > ((((bottom[b_idx]) << 12) / (4095 - (top[t_idx])))) ? ((((bottom[b_idx]) << 12) / (4095 - (top[t_idx])))) : (4095)))) - top[t_idx]) * opacity;
    }
}
}
