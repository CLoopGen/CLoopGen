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
for (i = 0; i < h + 3; i++) {
    tmp[0] = (src[0] + src[1]) * 15 - (src[-1] + src[2]) * 3 + pad;
    tmp[1] = (src[1] + src[2]) * 15 - (src[0] + src[3]) * 3 + pad;
    tmp[2] = (src[2] + src[3]) * 15 - (src[1] + src[4]) * 3 + pad;
    tmp[3] = (src[3] + src[4]) * 15 - (src[2] + src[5]) * 3 + pad;
    tmp += tmpStride;
    src += srcStride;
}
}
