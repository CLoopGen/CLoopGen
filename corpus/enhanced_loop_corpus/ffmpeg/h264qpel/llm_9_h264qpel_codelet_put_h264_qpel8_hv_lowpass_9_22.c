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
    tmp[0] = (src[0] + src[1]) * 25 - (src[-1] + src[2]) * 7 + (src[-2] + src[3]) * 2 + (src[-3] + src[4]) + pad;
    tmp[1] = (src[1] + src[2]) * 25 - (src[0] + src[3]) * 7 + (src[-1] + src[4]) * 2 + (src[-2] + src[5]) + pad;
    tmp[2] = (src[2] + src[3]) * 25 - (src[1] + src[4]) * 7 + (src[0] + src[5]) * 2 + (src[-1] + src[6]) + pad;
    tmp[3] = (src[3] + src[4]) * 25 - (src[2] + src[5]) * 7 + (src[1] + src[6]) * 2 + (src[0] + src[7]) + pad;
    tmp[4] = (src[4] + src[5]) * 25 - (src[3] + src[6]) * 7 + (src[2] + src[7]) * 2 + (src[1] + src[8]) + pad;
    tmp[5] = (src[5] + src[6]) * 25 - (src[4] + src[7]) * 7 + (src[3] + src[8]) * 2 + (src[2] + src[9]) + pad;
    tmp[6] = (src[6] + src[7]) * 25 - (src[5] + src[8]) * 7 + (src[4] + src[9]) * 2 + (src[3] + src[10]) + pad;
    tmp[7] = (src[7] + src[8]) * 25 - (src[6] + src[9]) * 7 + (src[5] + src[10]) * 2 + (src[4] + src[11]) + pad;
    tmp[8] = (src[8] + src[9]) * 25 - (src[7] + src[10]) * 7 + (src[6] + src[11]) * 2 + (src[5] + src[12]) + pad;
    tmp[9] = (src[9] + src[10]) * 25 - (src[8] + src[11]) * 7 + (src[7] + src[12]) * 2 + (src[6] + src[13]) + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
