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
    for (pixel = 0; pixel < width; pixel += 2) {
        int idx1 = pixel;
        int idx2 = (pixel + 1) >= width ? idx1 : pixel + 1;
        uint16_t val1_1 = src1w[idx1], val1_2 = src1w[idx2];
        uint16_t val2_1 = src2w[idx1], val2_2 = src2w[idx2];
        dstw[idx1] = ((val1_1 * factor1) + (val2_1 * factor2) + half) >> (16 - 1);
        if (idx2 != idx1) {
            dstw[idx2] = ((val1_2 * factor1) + (val2_2 * factor2) + half) >> (16 - 1);
        }
    }
    src1w += src1_linesize;
    src2w += src2_linesize;
    dstw += dst_linesize;
}
}
