#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern uint8_t *dst;
extern int dst_linesize;
extern  uint8_t *src;
extern int src_linesize;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 3; j < h - 3; j++) {
    for (int jj = -2; jj <= 2; jj++) {
        dst[jj * dst_linesize] = src[jj * src_linesize];
        if (w > 1)
            dst[jj * dst_linesize + 1] = src[jj * src_linesize + 1];
        for (i = 2; i < w - 2; i++) {
            dst[jj * dst_linesize + i] = (
                (src[(jj - 2) * src_linesize + i - 2] + src[(jj + 2) * src_linesize + i - 2]) * 2 +
                (src[(jj - 2) * src_linesize + i - 1] + src[(jj + 2) * src_linesize + i - 1]) * 4 +
                (src[(jj - 2) * src_linesize + i]     + src[(jj + 2) * src_linesize + i])     * 5 +
                (src[(jj - 2) * src_linesize + i + 1] + src[(jj + 2) * src_linesize + i + 1]) * 4 +
                (src[(jj - 2) * src_linesize + i + 2] + src[(jj + 2) * src_linesize + i + 2]) * 2 +
                (src[(jj - 1) * src_linesize + i - 2] + src[(jj + 1) * src_linesize + i - 2]) * 4 +
                (src[(jj - 1) * src_linesize + i - 1] + src[(jj + 1) * src_linesize + i - 1]) * 9 +
                (src[(jj - 1) * src_linesize + i]     + src[(jj + 1) * src_linesize + i])     *12 +
                (src[(jj - 1) * src_linesize + i + 1] + src[(jj + 1) * src_linesize + i + 1]) * 9 +
                (src[(jj - 1) * src_linesize + i + 2] + src[(jj + 1) * src_linesize + i + 2]) * 4 +
                src[jj * src_linesize + i - 2] * 5 +
                src[jj * src_linesize + i - 1] * 12 +
                src[jj * src_linesize + i]     * 15 +
                src[jj * src_linesize + i + 1] * 12 +
                src[jj * src_linesize + i + 2] * 5
            ) / 159;
        }
        if (w > 2)
            dst[jj * dst_linesize + i] = src[jj * src_linesize + i];
        if (w > 3)
            dst[jj * dst_linesize + i + 1] = src[jj * src_linesize + i + 1];
    }
    dst += 5 * dst_linesize;
    src += 5 * src_linesize;
    j += 4;
}
}
