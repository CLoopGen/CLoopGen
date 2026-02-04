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
for (i = 0; i < h; i++) {
    tmp[0] = (src[0] + src[1]) * 24 - (src[-1] + src[2]) * 6 + (src[-2] + src[3]) * 2 - (src[-3] + src[4]) + pad;
    tmp[1] = (src[1] + src[2]) * 24 - (src[0] + src[3]) * 6 + (src[-1] + src[4]) * 2 - (src[-2] + src[5]) + pad;
    tmp[2] = (src[2] + src[3]) * 24 - (src[1] + src[4]) * 6 + (src[0] + src[5]) * 2 - (src[-1] + src[6]) + pad;
    tmp[3] = (src[3] + src[4]) * 24 - (src[2] + src[5]) * 6 + (src[1] + src[6]) * 2 - (src[0] + src[7]) + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
