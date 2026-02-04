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
for (i = 0; i < h + 8; i += 2) {
    int32_t s0, s1, s2, s3, s4, s5, s6, s7;
    s0 = src[0]; s1 = src[1]; s2 = src[2]; s3 = src[3];
    s4 = src[4]; s5 = src[5]; s6 = src[6]; s7 = src[7];

    tmp[0] = (s0 + s1) * 20 - (src[-1] + s2) * 5 + (src[-2] + s3) + pad;
    tmp[1] = (s1 + s2) * 20 - (s0 + s3) * 5 + (src[-1] + s4) + pad;
    tmp[2] = (s2 + s3) * 20 - (s1 + s4) * 5 + (s0 + s5) + pad;
    tmp[3] = (s3 + s4) * 20 - (s2 + s5) * 5 + (s1 + s6) + pad;
    tmp[4] = (s4 + s5) * 20 - (s3 + s6) * 5 + (s2 + s7) + pad;
    tmp[5] = (s5 + s6) * 20 - (s4 + s7) * 5 + (s3 + src[8]) + pad;

    if (i + 1 < h + 8) {
        tmp += tmpStride;
        src += srcStride;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
