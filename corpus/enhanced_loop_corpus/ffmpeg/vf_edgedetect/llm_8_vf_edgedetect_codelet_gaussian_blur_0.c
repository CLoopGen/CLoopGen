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
for (j = 1; j < h - 1; j++) {
    dst[0] = src[0];
    if (w > 1)
        dst[1] = src[1];
    for (i = 2; i < w - 2; i += 2) {
        int sum1 = (src[-2 * src_linesize + i - 2] + src[2 * src_linesize + i - 2]) * 2 +
                   (src[-2 * src_linesize + i - 1] + src[2 * src_linesize + i - 1]) * 4 +
                   (src[-2 * src_linesize + i]     + src[2 * src_linesize + i])     * 5 +
                   (src[-2 * src_linesize + i + 1] + src[2 * src_linesize + i + 1]) * 4 +
                   (src[-2 * src_linesize + i + 2] + src[2 * src_linesize + i + 2]) * 2;
        int sum2 = (src[-src_linesize + i - 2] + src[src_linesize + i - 2]) * 4 +
                   (src[-src_linesize + i - 1] + src[src_linesize + i - 1]) * 9 +
                   (src[-src_linesize + i]     + src[src_linesize + i])     * 12 +
                   (src[-src_linesize + i + 1] + src[src_linesize + i + 1]) * 9 +
                   (src[-src_linesize + i + 2] + src[src_linesize + i + 2]) * 4;
        int sum3 = src[i - 2] * 5 + src[i - 1] * 12 + src[i] * 15 + src[i + 1] * 12 + src[i + 2] * 5;
        dst[i] = (sum1 + sum2 + sum3) / 159;

        if (i + 1 < w - 2) {
            sum1 = (src[-2 * src_linesize + i - 1] + src[2 * src_linesize + i - 1]) * 2 +
                   (src[-2 * src_linesize + i]     + src[2 * src_linesize + i])     * 4 +
                   (src[-2 * src_linesize + i + 1] + src[2 * src_linesize + i + 1]) * 5 +
                   (src[-2 * src_linesize + i + 2] + src[2 * src_linesize + i + 2]) * 4 +
                   (src[-2 * src_linesize + i + 3] + src[2 * src_linesize + i + 3]) * 2;
            sum2 = (src[-src_linesize + i - 1] + src[src_linesize + i - 1]) * 4 +
                   (src[-src_linesize + i]     + src[src_linesize + i])     * 9 +
                   (src[-src_linesize + i + 1] + src[src_linesize + i + 1]) * 12 +
                   (src[-src_linesize + i + 2] + src[src_linesize + i + 2]) * 9 +
                   (src[-src_linesize + i + 3] + src[src_linesize + i + 3]) * 4;
            sum3 = src[i - 1] * 5 + src[i] * 12 + src[i + 1] * 15 + src[i + 2] * 12 + src[i + 3] * 5;
            dst[i + 1] = (sum1 + sum2 + sum3) / 159;
        }
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
