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
    ptrdiff_t offset = 0;
    for (line = 0; line < height; line++) {
        uint8_t *dst_line = dstw + offset;
        const uint8_t *src1_line = src1w + offset;
        const uint8_t *src2_line = src2w + offset;
        for (pixel = 0; pixel < width; pixel++) {
            int temp1 = src1_line[pixel] * factor1;
            int temp2 = src2_line[pixel] * factor2;
            dst_line[pixel] = (temp1 + temp2 + half) >> 7;
        }
        offset += dst_linesize;
    }
}
