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
extern uint8_t *dstw;
extern uint8_t *src1w;
extern uint8_t *src2w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (line = 0; line < height; line++) {
    for (pixel = 0; pixel < width; pixel += 2) {
        dstw[pixel] = ((src1w[pixel] * factor1) + (src2w[pixel] * factor2) + half) >> (8 - 1);
        if (pixel + 1 < width) {
            dstw[pixel + 1] = ((src1w[pixel + 1] * factor1) + (src2w[pixel + 1] * factor2) + half) >> (8 - 1);
        }
    }
    src1w += src1_linesize;
    src2w += src2_linesize;
    dstw += dst_linesize;
}
}
