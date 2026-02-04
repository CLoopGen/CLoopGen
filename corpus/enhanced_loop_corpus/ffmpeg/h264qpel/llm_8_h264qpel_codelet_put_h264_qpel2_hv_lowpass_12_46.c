#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int h;
extern  int pad;
extern int i;
extern  uint16_t *src;
extern int32_t *tmp;
extern int tmpStride;
extern int srcStride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h + 10; i += 2) {
    int32_t val0, val1, val2, val3;
    val0 = (src[0] + src[1]) * 18 - (src[-1] + src[2]) * 4 + pad;
    val1 = (src[1] + src[2]) * 18 - (src[0] + src[3]) * 4 + pad;
    val2 = (src[2] + src[3]) * 18 - (src[1] + src[4]) * 4 + pad;
    val3 = (src[3] + src[4]) * 18 - (src[2] + src[5]) * 4 + pad;
    tmp[0] = val0 + (src[-2] + src[3]);
    tmp[1] = val1 + (src[-1] + src[4]);
    tmp[2] = val2 + (src[0] + src[5]);
    tmp[3] = val3 + (src[1] + src[6]);
    tmp += tmpStride;
    src += srcStride;
}
}
