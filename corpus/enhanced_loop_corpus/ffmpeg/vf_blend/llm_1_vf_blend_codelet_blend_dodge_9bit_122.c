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
        for (j = 0; j < width; j++) {
            int idx = i * (dst_linesize / sizeof(uint16_t)) + j;
            int top_idx = i * (top_linesize / sizeof(uint16_t)) + j;
            int bot_idx = i * (bottom_linesize / sizeof(uint16_t)) + j;
            dst[idx] = top[top_idx] + (((((top[top_idx]) == 511) ? (top[top_idx]) : ((511) > ((((bottom[bot_idx]) << 9) / (511 - (top[top_idx])))) ? ((((bottom[bot_idx]) << 9) / (511 - (top[top_idx])))) : (511)))) - top[top_idx]) * opacity;
        }
    }
}
