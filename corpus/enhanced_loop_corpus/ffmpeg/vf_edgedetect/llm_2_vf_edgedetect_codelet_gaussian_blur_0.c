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
        int offset = i;
        uint8_t *src_ptr = src + offset;
        dst[i] = ((src_ptr[-2 * src_linesize - 2] + src_ptr[2 * src_linesize - 2]) * 2 +
                  (src_ptr[-2 * src_linesize - 1] + src_ptr[2 * src_linesize - 1]) * 4 +
                  (src_ptr[-2 * src_linesize + 0] + src_ptr[2 * src_linesize + 0]) * 5 +
                  (src_ptr[-2 * src_linesize + 1] + src_ptr[2 * src_linesize + 1]) * 4 +
                  (src_ptr[-2 * src_linesize + 2] + src_ptr[2 * src_linesize + 2]) * 2 +
                  (src_ptr[-src_linesize - 2]   + src_ptr[src_linesize - 2])   * 4 +
                  (src_ptr[-src_linesize - 1]   + src_ptr[src_linesize - 1])   * 9 +
                  (src_ptr[-src_linesize + 0]   + src_ptr[src_linesize + 0])   *12 +
                  (src_ptr[-src_linesize + 1]   + src_ptr[src_linesize + 1])   * 9 +
                  (src_ptr[-src_linesize + 2]   + src_ptr[src_linesize + 2])   * 4 +
                  src_ptr[-2] * 5 + src_ptr[-1] * 12 + src_ptr[0] * 15 +
                  src_ptr[1] * 12 + src_ptr[2] * 5) / 159;
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
