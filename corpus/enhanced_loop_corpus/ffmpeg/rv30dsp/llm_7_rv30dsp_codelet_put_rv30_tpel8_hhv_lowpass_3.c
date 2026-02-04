#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int w;
extern  int h;
extern  uint8_t *cm;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j, i;
    for (j = 0; j < h; j++) {
        for (i = 0; i < w; i += 2) {
            int base_idx = srcStride * 0 + i;
            int val1 = (src[srcStride * -1 + i - 1] - 12 * src[srcStride * -1 + i + 1] - 6 * src[srcStride * -1 + i] + src[srcStride * -1 + i + 2] +
                        -12 * src[base_idx - 1] + 144 * src[base_idx + 1] + 72 * src[base_idx] - 12 * src[base_idx + 2] +
                        -6 * src[srcStride * 1 + i - 1] + 72 * src[srcStride * 1 + i + 1] + 36 * src[srcStride * 1 + i] - 6 * src[srcStride * 1 + i + 2] +
                        src[srcStride * 2 + i - 1] - 12 * src[srcStride * 2 + i + 1] - 6 * src[srcStride * 2 + i] + src[srcStride * 2 + i + 2] + 128) >> 8;

            dst[i] = cm[val1];

            if (i + 1 < w) {
                int val2 = (src[srcStride * -1 + i] - 12 * src[srcStride * -1 + i + 2] - 6 * src[srcStride * -1 + i + 1] + src[srcStride * -1 + i + 3] +
                            -12 * src[base_idx] + 144 * src[base_idx + 2] + 72 * src[base_idx + 1] - 12 * src[base_idx + 3] +
                            -6 * src[srcStride * 1 + i] + 72 * src[srcStride * 1 + i + 2] + 36 * src[srcStride * 1 + i + 1] - 6 * src[srcStride * 1 + i + 3] +
                            src[srcStride * 2 + i] - 12 * src[srcStride * 2 + i + 2] - 6 * src[srcStride * 2 + i + 1] + src[srcStride * 2 + i + 3] + 128) >> 8;
                dst[i + 1] = cm[val2];
            }
        }
        src += srcStride;
        dst += dstStride;
    }
}
