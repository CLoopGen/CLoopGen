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
int32_t prev_tmp0 = 0;
for (i = 0; i < h + 5; i++) {
    int32_t val0 = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad + prev_tmp0;
    int32_t val1 = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad + val0;
    int32_t val2 = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad + val1;
    int32_t val3 = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad + val2;
    tmp[0] = val0;
    tmp[1] = val1;
    tmp[2] = val2;
    tmp[3] = val3;
    prev_tmp0 = val3; // Introduce loop-carried dependency (WAW and RAW)
    tmp += tmpStride;
    src += srcStride;
}
}
