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
for (i = 0; i < h; i++) {
    int32_t t0, t1, t2, t3;

    t0 = (src[0] + src[1]) * 20;
    t1 = (src[-1] + src[2]) * 5;
    t2 = (src[-2] + src[3]);
    tmp[0] = t0 - t1 + t2 + pad;

    t0 = (src[1] + src[2]) * 20;
    t1 = (src[0] + src[3]) * 5;
    t2 = (src[-1] + src[4]);
    tmp[1] = t0 - t1 + t2 + pad;

    tmp += tmpStride;
    src += srcStride;
}
}
