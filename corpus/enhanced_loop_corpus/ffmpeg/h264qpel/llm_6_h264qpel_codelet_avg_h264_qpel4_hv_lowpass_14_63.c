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
for (i = 0; i < h + 5; i++) {
    int32_t t0, t1, t2, t3;
    t0 = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
    t1 = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    t2 = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
    t3 = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;
    tmp[0] = t0;
    tmp[1] = t1;
    tmp[2] = t2;
    tmp[3] = t3;
    tmp += tmpStride;
    src += srcStride;
}
}
