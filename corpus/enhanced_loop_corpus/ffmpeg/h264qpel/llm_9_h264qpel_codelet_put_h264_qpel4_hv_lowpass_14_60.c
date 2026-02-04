#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 8; i += 2) {
    int32_t a0 = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
    int32_t a1 = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    int32_t a2 = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
    int32_t a3 = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;
    int32_t b0 = (src[4] + src[5]) * 20 - (src[3] + src[6]) * 5 + (src[2] + src[7]) + pad;
    int32_t b1 = (src[5] + src[6]) * 20 - (src[4] + src[7]) * 5 + (src[3] + src[8]) + pad;
    int32_t b2 = (src[6] + src[7]) * 20 - (src[5] + src[8]) * 5 + (src[4] + src[9]) + pad;
    int32_t b3 = (src[7] + src[8]) * 20 - (src[6] + src[9]) * 5 + (src[5] + src[10]) + pad;

    tmp[0] = a0; tmp[1] = a1; tmp[2] = a2; tmp[3] = a3;
    tmp[tmpStride] = b0; tmp[tmpStride+1] = b1; tmp[tmpStride+2] = b2; tmp[tmpStride+3] = b3;

    tmp += 2 * tmpStride;
    src += 2 * srcStride;
}
}
