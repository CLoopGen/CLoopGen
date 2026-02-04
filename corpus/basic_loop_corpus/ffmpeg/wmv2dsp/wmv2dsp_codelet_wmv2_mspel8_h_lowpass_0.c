#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < h; i++) {
    dst[0] = cm[(9 * (src[0] + src[1]) - (src[-1] + src[2]) + 8) >> 4];
    dst[1] = cm[(9 * (src[1] + src[2]) - (src[0] + src[3]) + 8) >> 4];
    dst[2] = cm[(9 * (src[2] + src[3]) - (src[1] + src[4]) + 8) >> 4];
    dst[3] = cm[(9 * (src[3] + src[4]) - (src[2] + src[5]) + 8) >> 4];
    dst[4] = cm[(9 * (src[4] + src[5]) - (src[3] + src[6]) + 8) >> 4];
    dst[5] = cm[(9 * (src[5] + src[6]) - (src[4] + src[7]) + 8) >> 4];
    dst[6] = cm[(9 * (src[6] + src[7]) - (src[5] + src[8]) + 8) >> 4];
    dst[7] = cm[(9 * (src[7] + src[8]) - (src[6] + src[9]) + 8) >> 4];
    dst += dstStride;
    src += srcStride;
}

}
