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
for (i = 0; i < h + 2; i += 2) {
    int32_t t0, t1, t2, t3;
    t0 = (src[0] + src[1]) * 18 - (src[-1] + src[2]) * 4 + pad;
    t1 = (src[1] + src[2]) * 18 - (src[0] + src[3]) * 4 + pad;
    t2 = (src[2] + src[3]) * 18 - (src[1] + src[4]) * 4 + pad;
    t3 = (src[3] + src[4]) * 18 - (src[2] + src[5]) * 4 + pad;

    tmp[0] = t0 + (src[-2] + src[3]);
    tmp[1] = t1 + (src[-1] + src[4]);
    tmp[2] = t2 + (src[0]  + src[5]);
    tmp[3] = t3 + (src[1]  + src[6]);

    if (i + 1 < h + 2) {
        src += srcStride;
        tmp += tmpStride;

        tmp[0] = (src[0] + src[1]) * 18 - (src[-1] + src[2]) * 4 + (src[-2] + src[3]) + pad;
        tmp[1] = (src[1] + src[2]) * 18 - (src[0] + src[3]) * 4 + (src[-1] + src[4]) + pad;
        tmp[2] = (src[2] + src[3]) * 18 - (src[1] + src[4]) * 4 + (src[0]  + src[5]) + pad;
        tmp[3] = (src[3] + src[4]) * 18 - (src[2] + src[5]) * 4 + (src[1]  + src[6]) + pad;
    }

    tmp += tmpStride;
    src += srcStride;
}
}
