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
    for (i = 2; i < w - 2; i += 2) {
        uint8_t val1, val2;
        int idx1 = i, idx2 = i + 1;

        val1 = ((src[-2 * src_linesize + idx1 - 2] + src[2 * src_linesize + idx1 - 2]) * 2 +
                (src[-2 * src_linesize + idx1 - 1] + src[2 * src_linesize + idx1 - 1]) * 4 +
                (src[-2 * src_linesize + idx1]     + src[2 * src_linesize + idx1])     * 5 +
                (src[-2 * src_linesize + idx1 + 1] + src[2 * src_linesize + idx1 + 1]) * 4 +
                (src[-2 * src_linesize + idx1 + 2] + src[2 * src_linesize + idx1 + 2]) * 2 +
                (src[-src_linesize + idx1 - 2]     + src[src_linesize + idx1 - 2])     * 4 +
                (src[-src_linesize + idx1 - 1]     + src[src_linesize + idx1 - 1])     * 9 +
                (src[-src_linesize + idx1]         + src[src_linesize + idx1])         *12 +
                (src[-src_linesize + idx1 + 1]     + src[src_linesize + idx1 + 1])     * 9 +
                (src[-src_linesize + idx1 + 2]     + src[src_linesize + idx1 + 2])     * 4 +
                src[idx1 - 2] * 5 + src[idx1 - 1] * 12 + src[idx1] * 15 +
                src[idx1 + 1] * 12 + src[idx1 + 2] * 5) / 159;

        if (idx2 < w - 2) {
            val2 = ((src[-2 * src_linesize + idx2 - 2] + src[2 * src_linesize + idx2 - 2]) * 2 +
                    (src[-2 * src_linesize + idx2 - 1] + src[2 * src_linesize + idx2 - 1]) * 4 +
                    (src[-2 * src_linesize + idx2]     + src[2 * src_linesize + idx2])     * 5 +
                    (src[-2 * src_linesize + idx2 + 1] + src[2 * src_linesize + idx2 + 1]) * 4 +
                    (src[-2 * src_linesize + idx2 + 2] + src[2 * src_linesize + idx2 + 2]) * 2 +
                    (src[-src_linesize + idx2 - 2]     + src[src_linesize + idx2 - 2])     * 4 +
                    (src[-src_linesize + idx2 - 1]     + src[src_linesize + idx2 - 1])     * 9 +
                    (src[-src_linesize + idx2]         + src[src_linesize + idx2])         *12 +
                    (src[-src_linesize + idx2 + 1]     + src[src_linesize + idx2 + 1])     * 9 +
                    (src[-src_linesize + idx2 + 2]     + src[src_linesize + idx2 + 2])     * 4 +
                    src[idx2 - 2] * 5 + src[idx2 - 1] * 12 + src[idx2] * 15 +
                    src[idx2 + 1] * 12 + src[idx2 + 2] * 5) / 159;
        } else {
            val2 = src[idx2];
        }

        dst[idx1] = val1;
        if (idx2 < w - 2)
            dst[idx2] = val2;
    }
    if (w > 2)
        dst[i] = src[i];
    if (w > 3)
        dst[i + 1] = src[i + 1];
    dst += dst_linesize;
    src += src_linesize;
}
}
