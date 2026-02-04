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
        ptrdiff_t tj0 = j, tj1 = j + 1;
        if (tj1 >= width) tj1 = tj0;

        uint16_t top0 = top[tj0], top1 = top[tj1];
        uint16_t bot0 = bottom[tj0], bot1 = bottom[tj1];

        dst[tj0] = top0 + (((top0 == 0) ? top0 : ((0 > (511 - ((511 - bot0) << 9) / top0)) ? 0 : (511 - ((511 - bot0) << 9) / top0))) - top0) * opacity;
        dst[tj1] = top1 + (((top1 == 0) ? top1 : ((0 > (511 - ((511 - bot1) << 9) / top1)) ? 0 : (511 - ((511 - bot1) << 9) / top1))) - top1) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
