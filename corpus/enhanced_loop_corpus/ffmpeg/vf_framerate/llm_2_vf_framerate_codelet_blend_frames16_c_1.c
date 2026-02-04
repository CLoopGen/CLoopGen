#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t src1_linesize;
extern ptrdiff_t src2_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern int factor1;
extern int factor2;
extern int half;
extern int line;
extern int pixel;
extern uint16_t *dstw;
extern uint16_t *src1w;
extern uint16_t *src2w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (line = 0; line < height; line++) {
    uint16_t *src1_row = src1w + line * (src1_linesize / sizeof(uint16_t));
    uint16_t *src2_row = src2w + line * (src2_linesize / sizeof(uint16_t));
    uint16_t *dst_row = dstw + line * (dst_linesize / sizeof(uint16_t));
    for (pixel = 0; pixel < width; pixel++) {
        dst_row[pixel] = ((src1_row[pixel] * factor1) + (src2_row[pixel] * factor2) + half) >> (16 - 1);
    }
}
}
