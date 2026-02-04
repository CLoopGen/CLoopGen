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
for (i = 0; i < h + 10; i += 2) {
    tmp[0] = (src[0] + src[1]) * 15 - (src[-1] + src[2]) * 3 + pad;
    tmp[1] = (src[1] + src[2]) * 15 - (src[0] + src[3]) * 3 + pad;
    if (i + 1 < h + 10) {
        tmp[tmpStride] = (src[srcStride] + src[srcStride+1]) * 15 - (src[srcStride-1] + src[srcStride+2]) * 3 + pad;
        tmp[tmpStride + 1] = (src[srcStride+1] + src[srcStride+2]) * 15 - (src[srcStride] + src[srcStride+3]) * 3 + pad;
    }
    tmp += 2 * tmpStride;
    src += 2 * srcStride;
}
}
