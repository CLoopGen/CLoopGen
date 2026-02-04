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
    dst[1] = src[1];
    for (i = 2; i < w - 2; i++) {
        dst[i] = ((src[-2 * src_linesize + i - 2] + src[2 * src_linesize + i - 2]) * 2 + (src[-2 * src_linesize + i - 1] + src[2 * src_linesize + i - 1]) * 4 + (src[-2 * src_linesize + i] + src[2 * src_linesize + i]) * 5 + (src[-2 * src_linesize + i + 1] + src[2 * src_linesize + i + 1]) * 4 + (src[-2 * src_linesize + i + 2] + src[2 * src_linesize + i + 2]) * 2 + (src[-src_linesize + i - 2] + src[src_linesize + i - 2]) * 4 + (src[-src_linesize + i - 1] + src[src_linesize + i - 1]) * 9 + (src[-src_linesize + i] + src[src_linesize + i]) * 12 + (src[-src_linesize + i + 1] + src[src_linesize + i + 1]) * 9 + (src[-src_linesize + i + 2] + src[src_linesize + i + 2]) * 4 + src[i - 2] * 5 + src[i - 1] * 12 + src[i] * 15 + src[i + 1] * 12 + src[i + 2] * 5) / 159;
    }
    if (w > 2)
        dst[i] = src[i];
    dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
