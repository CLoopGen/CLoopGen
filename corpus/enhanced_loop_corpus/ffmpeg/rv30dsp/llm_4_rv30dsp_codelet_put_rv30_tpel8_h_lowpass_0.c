#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int C1;
extern  int C2;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    int offset = 0;
    if (h > 10 && i % 2 == 0) {
        dst[0] = cm[(-(src[-1 + offset] + src[2 + offset]) + src[0 + offset] * C1 + src[1 + offset] * C2 + 8) >> 4];
        dst[1] = cm[(-(src[0 + offset] + src[3 + offset]) + src[1 + offset] * C1 + src[2 + offset] * C2 + 8) >> 4];
        dst[2] = cm[(-(src[1 + offset] + src[4 + offset]) + src[2 + offset] * C1 + src[3 + offset] * C2 + 8) >> 4];
        dst[3] = cm[(-(src[2 + offset] + src[5 + offset]) + src[3 + offset] * C1 + src[4 + offset] * C2 + 8) >> 4];
        dst[4] = cm[(-(src[3 + offset] + src[6 + offset]) + src[4 + offset] * C1 + src[5 + offset] * C2 + 8) >> 4];
        dst[5] = cm[(-(src[4 + offset] + src[7 + offset]) + src[5 + offset] * C1 + src[6 + offset] * C2 + 8) >> 4];
        dst[6] = cm[(-(src[5 + offset] + src[8 + offset]) + src[6 + offset] * C1 + src[7 + offset] * C2 + 8) >> 4];
        dst[7] = cm[(-(src[6 + offset] + src[9 + offset]) + src[7 + offset] * C1 + src[8 + offset] * C2 + 8) >> 4];
    } else {
        for (int j = 0; j < 8; j++) {
            dst[j] = cm[0];
        }
    }
    dst += dstStride;
    src += srcStride;
}
}
