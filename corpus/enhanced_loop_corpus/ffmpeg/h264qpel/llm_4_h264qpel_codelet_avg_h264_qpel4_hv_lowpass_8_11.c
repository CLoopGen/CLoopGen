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
for (i = 0; i < h + 5; i++) {
    if (i % 2 == 0) {
        tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
        tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
        tmp[2] = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
        tmp[3] = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;
    } else {
        tmp[0] = (src[0] + src[1]) * 18 - (src[-1] + src[2]) * 4 + (src[-2] + src[3]) + pad;
        tmp[1] = (src[1] + src[2]) * 18 - (src[0] + src[3]) * 4 + (src[-1] + src[4]) + pad;
        tmp[2] = (src[2] + src[3]) * 18 - (src[1] + src[4]) * 4 + (src[0] + src[5]) + pad;
        tmp[3] = (src[3] + src[4]) * 18 - (src[2] + src[5]) * 4 + (src[1] + src[6]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
