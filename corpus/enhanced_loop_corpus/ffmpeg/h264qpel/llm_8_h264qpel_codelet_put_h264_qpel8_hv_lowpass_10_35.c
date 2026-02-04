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
for (i = 0; i < h + 3; i++) {
    tmp[0] = (src[1] + src[2]) * 18 - src[0] * 5 + src[3] * 2 + pad;
    tmp[1] = (src[2] + src[3]) * 18 - src[1] * 5 + src[4] * 2 + pad;
    tmp[2] = (src[3] + src[4]) * 18 - src[2] * 5 + src[5] * 2 + pad;
    tmp[3] = (src[4] + src[5]) * 18 - src[3] * 5 + src[6] * 2 + pad;
    tmp[4] = (src[5] + src[6]) * 18 - src[4] * 5 + src[7] * 2 + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
