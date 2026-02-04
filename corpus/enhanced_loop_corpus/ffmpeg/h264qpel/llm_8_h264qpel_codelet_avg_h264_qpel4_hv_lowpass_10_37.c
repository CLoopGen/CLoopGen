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
for (i = 0; i < h + 2; i += 2) {
    tmp[0] = (src[0] + src[1]) * 18 - (src[-1] + src[2]) * 4 + pad;
    tmp[1] = (src[1] + src[2]) * 18 - (src[0] + src[3]) * 4 + pad;
    tmp[tmpStride] = (src[srcStride] + src[srcStride+1]) * 18 - (src[-1+srcStride] + src[2+srcStride]) * 4 + pad;
    tmp[tmpStride+1] = (src[srcStride+1] + src[srcStride+2]) * 18 - (src[srcStride] + src[srcStride+3]) * 4 + pad;

    tmp += 2 * tmpStride;
    src += 2 * srcStride;
}
}
