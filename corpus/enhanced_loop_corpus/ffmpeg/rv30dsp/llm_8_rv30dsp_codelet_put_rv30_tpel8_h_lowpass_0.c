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
    dst[0] = cm[(-(src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + 8) >> 4];
    dst[1] = cm[(-(src[0] + src[3]) + src[1] * C1 + src[2] * C2 + 8) >> 4];
    dst[2] = cm[(-(src[1] + src[4]) + src[2] * C1 + src[3] * C2 + 8) >> 4];
    dst[3] = cm[(-(src[2] + src[5]) + src[3] * C1 + src[4] * C2 + 8) >> 4];
    dst += dstStride;
    src += srcStride;
}
}
