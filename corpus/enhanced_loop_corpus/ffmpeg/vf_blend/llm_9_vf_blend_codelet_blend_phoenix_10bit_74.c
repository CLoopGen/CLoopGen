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
for (i = 0; i < height; i += 2) {
    ptrdiff_t dst_offset1 = 0, dst_offset2 = dst_linesize;
    ptrdiff_t top_offset1 = 0, top_offset2 = top_linesize;
    ptrdiff_t bot_offset1 = 0, bot_offset2 = bottom_linesize;
    for (j = 0; j < width; j++) {
        dst[dst_offset1 + j] = top[top_offset1 + j] + 
            ((((top[top_offset1 + j]) > (bottom[bot_offset1 + j]) ? (bottom[bot_offset1 + j]) : (top[top_offset1 + j])) - 
              ((top[top_offset1 + j]) > (bottom[bot_offset1 + j]) ? (top[top_offset1 + j]) : (bottom[bot_offset1 + j])) + 1023) - 
             top[top_offset1 + j]) * opacity;

        if (i + 1 < height) {
            dst[dst_offset2 + j] = top[top_offset2 + j] + 
                ((((top[top_offset2 + j]) > (bottom[bot_offset2 + j]) ? (bottom[bot_offset2 + j]) : (top[top_offset2 + j])) - 
                  ((top[top_offset2 + j]) > (bottom[bot_offset2 + j]) ? (top[top_offset2 + j]) : (bottom[bot_offset2 + j])) + 1023) - 
                 top[top_offset2 + j]) * opacity;
        }
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
