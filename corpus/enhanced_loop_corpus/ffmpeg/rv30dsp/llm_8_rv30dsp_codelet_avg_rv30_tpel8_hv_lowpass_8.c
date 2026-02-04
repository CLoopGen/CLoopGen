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
for (j = 0; j < h; j++) {
    for (i = 0; i < w; i += 2) {
        int base_idx = srcStride * 0 + i;
        int val1 = cm[(src[srcStride * -1 + i] - 8 * src[base_idx] + 4 * src[base_idx + 1] + 
                      -8 * src[srcStride * 1 + i] + 64 * src[base_idx] + 32 * src[base_idx + 1] + 
                      4 * src[srcStride * 1 + i] + 32 * src[base_idx] + 16 * src[base_idx + 1] + 128) >> 8];
        int val2 = cm[(src[srcStride * -1 + i + 1] - 8 * src[base_idx + 1] + 4 * src[base_idx + 2] + 
                      -8 * src[srcStride * 1 + i + 1] + 64 * src[base_idx + 1] + 32 * src[base_idx + 2] + 
                      4 * src[srcStride * 1 + i + 1] + 32 * src[base_idx + 1] + 16 * src[base_idx + 2] + 128) >> 8];
        dst[i]     = ((dst[i]     + val1 + 1) >> 1);
        if (i + 1 < w) {
            dst[i + 1] = ((dst[i + 1] + val2 + 1) >> 1);
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
