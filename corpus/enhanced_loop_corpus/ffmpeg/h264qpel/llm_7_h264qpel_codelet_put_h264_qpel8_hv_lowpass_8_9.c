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
extern  uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int16_t prev_tmp7 = 0;
for (i = 0; i < h + 5; i++) {
    tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
    tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad + tmp[0];
    tmp[2] = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad + tmp[1];
    tmp[3] = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad + tmp[2];
    tmp[4] = (src[4] + src[5]) * 20 - (src[3] + src[6]) * 5 + (src[2] + src[7]) + pad + tmp[3];
    tmp[5] = (src[5] + src[6]) * 20 - (src[4] + src[7]) * 5 + (src[3] + src[8]) + pad + tmp[4];
    tmp[6] = (src[6] + src[7]) * 20 - (src[5] + src[8]) * 5 + (src[4] + src[9]) + pad + tmp[5];
    tmp[7] = (src[7] + src[8]) * 20 - (src[6] + src[9]) * 5 + (src[5] + src[10]) + pad + tmp[6] + prev_tmp7;

    prev_tmp7 = tmp[7];

    tmp += tmpStride;
    src += srcStride;
}
}
