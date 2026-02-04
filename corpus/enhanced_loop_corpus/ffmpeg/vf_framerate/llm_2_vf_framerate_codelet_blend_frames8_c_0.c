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
    uint8_t *src1_row = src1w;
    uint8_t *src2_row = src2w;
    uint8_t *dst_row = dstw;
    for (pixel = 0; pixel < width; pixel += 4) {
        dst_row[pixel]     = ((src1_row[pixel] * factor1) + (src2_row[pixel] * factor2) + half) >> 7;
        if (pixel + 1 < width)
            dst_row[pixel+1] = ((src1_row[pixel+1] * factor1) + (src2_row[pixel+1] * factor2) + half) >> 7;
        if (pixel + 2 < width)
            dst_row[pixel+2] = ((src1_row[pixel+2] * factor1) + (src2_row[pixel+2] * factor2) + half) >> 7;
        if (pixel + 3 < width)
            dst_row[pixel+3] = ((src1_row[pixel+3] * factor1) + (src2_row[pixel+3] * factor2) + half) >> 7;
    }
    src1w += src1_linesize;
    src2w += src2_linesize;
    dstw += dst_linesize;
}
}
