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
for (i = 0; i < h; i++) {
    tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + pad;
    tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + pad;
    tmp += tmpStride;
    src += srcStride;
    if (i % 2 == 0) {
        tmp[0] = (src[-1] + src[0]) * 10 + pad;
        tmp += tmpStride;
        src += srcStride;
    }
}
}
