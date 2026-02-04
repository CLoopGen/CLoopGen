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
    for (j = 0; j < width; j += 2) {
        int idx1 = j;
        int idx2 = j + 1;
        uint16_t top1 = top[idx1];
        uint16_t top2 = top[idx2];
        uint16_t bot1 = bottom[idx1];
        uint16_t bot2 = bottom[idx2];
        
        dst[idx1] = top1 + ((((1023) > (top1 + bot1) ? (top1 + bot1) : (1023))) - top1) * opacity;
        if (idx2 < width) {
            dst[idx2] = top2 + ((((1023) > (top2 + bot2) ? (top2 + bot2) : (1023))) - top2) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
