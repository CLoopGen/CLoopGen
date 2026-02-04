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
        int offset1 = srcStride * -1 + i;
        int offset2 = srcStride * 0 + i;
        int offset3 = srcStride * 1 + i;
        int offset4 = srcStride * 2 + i;
        
        int val1 = src[offset1 - 1] - 12 * src[offset1] - 6 * src[offset1 + 1] + src[offset1 + 2];
        int val2 = -12 * src[offset2 - 1] + 144 * src[offset2] + 72 * src[offset2 + 1] - 12 * src[offset2 + 2];
        int val3 = -6 * src[offset3 - 1] + 72 * src[offset3] + 36 * src[offset3 + 1] - 6 * src[offset3 + 2];
        int val4 = src[offset4 - 1] - 12 * src[offset4] - 6 * src[offset4 + 1] + src[offset4 + 2];
        
        int sum = val1 + val2 + val3 + val4 + 128;
        dst[i] = cm[sum >> 8];
        
        if (i + 1 < w) {
            offset1++; offset2++; offset3++; offset4++;
            val1 = src[offset1 - 1] - 12 * src[offset1] - 6 * src[offset1 + 1] + src[offset1 + 2];
            val2 = -12 * src[offset2 - 1] + 144 * src[offset2] + 72 * src[offset2 + 1] - 12 * src[offset2 + 2];
            val3 = -6 * src[offset3 - 1] + 72 * src[offset3] + 36 * src[offset3 + 1] - 6 * src[offset3 + 2];
            val4 = src[offset4 - 1] - 12 * src[offset4] - 6 * src[offset4 + 1] + src[offset4 + 2];
            sum = val1 + val2 + val3 + val4 + 128;
            dst[i + 1] = cm[sum >> 8];
        }
    }
    src += srcStride;
    dst += dstStride;
}
}
