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
for (j = 2; j < h - 2; j++) {
    dst[0] = src[0];
    if (w > 1)
        dst[1] = src[1];
    for (i = 2; i < w - 2; i++) {
        int temp = 0;
        temp += (src[-2 * src_linesize + i - 2] + src[2 * src_linesize + i - 2]) * 2;
        temp += (src[-2 * src_linesize + i - 1] + src[2 * src_linesize + i - 1]) * 4;
        temp += (src[-2 * src_linesize + i]     + src[2 * src_linesize + i])     * 5;
        temp += (src[-2 * src_linesize + i + 1] + src[2 * src_linesize + i + 1]) * 4;
        temp += (src[-2 * src_linesize + i + 2] + src[2 * src_linesize + i + 2]) * 2;
        temp += (src[-src_linesize + i - 2]     + src[src_linesize + i - 2])     * 4;
        temp += (src[-src_linesize + i - 1]     + src[src_linesize + i - 1])     * 9;
        temp += (src[-src_linesize + i]         + src[src_linesize + i])         *12;
        temp += (src[-src_linesize + i + 1]     + src[src_linesize + i + 1])     * 9;
        temp += (src[-src_linesize + i + 2]     + src[src_linesize + i + 2])     * 4;
        temp += src[i - 2] * 5;
        temp += src[i - 1] * 12;
        temp += src[i]     * 15;
        temp += src[i + 1] * 12;
        temp += src[i + 2] * 5;
        dst[i] = temp / 159;
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
