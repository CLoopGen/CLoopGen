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
    tmp[0] = (src[0] + src[1]) * 25 - (src[-1] + src[2]) * 7 + (src[-2] + src[3]) * 2 - (src[-3] + src[4]) + pad;
    tmp[1] = (src[1] + src[2]) * 25 - (src[0] + src[3]) * 7 + (src[-1] + src[4]) * 2 - (src[-2] + src[5]) + pad;
    tmp[2] = (src[2] + src[3]) * 25 - (src[1] + src[4]) * 7 + (src[0] + src[5]) * 2 - (src[-1] + src[6]) + pad;
    tmp[3] = (src[3] + src[4]) * 25 - (src[2] + src[5]) * 7 + (src[1] + src[6]) * 2 - (src[0] + src[7]) + pad;
    tmp[4] = (src[4] + src[5]) * 25 - (src[3] + src[6]) * 7 + (src[2] + src[7]) * 2 - (src[1] + src[8]) + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
