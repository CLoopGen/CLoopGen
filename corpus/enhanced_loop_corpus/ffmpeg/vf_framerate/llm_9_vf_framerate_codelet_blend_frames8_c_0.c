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
    pixel = 0;
    for (; pixel <= width - 4; pixel += 4) {
        dstw[pixel]     = ((src1w[pixel]     * factor1) + (src2w[pixel]     * factor2) + half) >> 7;
        dstw[pixel + 1] = ((src1w[pixel + 1] * factor1) + (src2w[pixel + 1] * factor2) + half) >> 7;
        dstw[pixel + 2] = ((src1w[pixel + 2] * factor1) + (src2w[pixel + 2] * factor2) + half) >> 7;
        dstw[pixel + 3] = ((src1w[pixel + 3] * factor1) + (src2w[pixel + 3] * factor2) + half) >> 7;
    }
    for (; pixel < width; pixel++) {
        dstw[pixel] = ((src1w[pixel] * factor1) + (src2w[pixel] * factor2) + half) >> 7;
    }
    src1w += src1_linesize;
    src2w += src2_linesize;
    dstw += dst_linesize;
}
}
