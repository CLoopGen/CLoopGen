#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *tmp;
extern int tmpStride;
extern int srcStride;
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 8; i++) {
    tmp[0] = ((src[0] + src[1]) * 22 - (src[-1] + src[2]) * 6 + (src[-2] + src[3]) + pad) >> 1;
    tmp[1] = ((src[1] + src[2]) * 22 - (src[0] + src[3]) * 6 + (src[-1] + src[4]) + pad) >> 1;
    tmp[2] = ((src[2] + src[3]) * 22 - (src[1] + src[4]) * 6 + (src[0] + src[5]) + pad) >> 1;
    tmp[3] = ((src[3] + src[4]) * 22 - (src[2] + src[5]) * 6 + (src[1] + src[6]) + pad) >> 1;
    tmp[4] = ((src[4] + src[5]) * 22 - (src[3] + src[6]) * 6 + (src[2] + src[7]) + pad) >> 1;
    tmp[5] = ((src[5] + src[6]) * 22 - (src[4] + src[7]) * 6 + (src[3] + src[8]) + pad) >> 1;

    tmp += tmpStride;
    src += srcStride;
}
}
