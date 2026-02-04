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
    if (i >= h / 2) {
        tmp[0] = (src[0] + src[1]) * 22 - (src[-1] + src[2]) * 6 + (src[-2] + src[3]) * 2 + pad;
        tmp[1] = (src[1] + src[2]) * 22 - (src[0] + src[3]) * 6 + (src[-1] + src[4]) * 2 + pad;
    } else {
        tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
        tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
