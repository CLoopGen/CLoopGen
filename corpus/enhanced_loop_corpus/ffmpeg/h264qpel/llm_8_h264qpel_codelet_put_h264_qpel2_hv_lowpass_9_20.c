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
for (i = 0; i < h + 10; i += 2) {
    int16_t val0, val1;
    uint16_t s0 = src[0], s1 = src[1], s2 = src[2], s3 = src[3], s4 = src[4], s_1 = src[-1], s_2 = src[-2];
    
    val0 = (s0 + s1) * 20 - (s_1 + s3) * 5 + (s_2 + s3) + pad;
    val1 = (s1 + s2) * 20 - (s0 + s3) * 5 + (s_1 + s4) + pad;

    tmp[0] = val0;
    tmp[1] = val1;

    if (i + 1 < h + 10) {
        uint16_t s5 = src[5], s6 = src[6];
        int16_t val2 = (s2 + s3) * 20 - (s1 + s4) * 5 + (s0 + s5) + pad;
        int16_t val3 = (s3 + s4) * 20 - (s2 + s5) * 5 + (s1 + s6) + pad;
        tmp[tmpStride] = val2;
        tmp[tmpStride + 1] = val3;
    }

    tmp += 2 * tmpStride;
    src += 2 * srcStride;
}
}
