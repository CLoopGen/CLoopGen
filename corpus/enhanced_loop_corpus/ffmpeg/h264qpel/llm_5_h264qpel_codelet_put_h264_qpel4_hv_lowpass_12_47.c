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
    int offset = (i < (h + 5) / 2) ? 0 : 1;
    if (i >= h) continue;

    tmp[0] = (src[0 + offset] + src[1 + offset]) * 20 - (src[-1 + offset] + src[2 + offset]) * 5 + (src[-2 + offset] + src[3 + offset]) + pad;
    tmp[1] = (src[1 + offset] + src[2 + offset]) * 20 - (src[0 + offset] + src[3 + offset]) * 5 + (src[-1 + offset] + src[4 + offset]) + pad;
    tmp[2] = (src[2 + offset] + src[3 + offset]) * 20 - (src[1 + offset] + src[4 + offset]) * 5 + (src[0 + offset] + src[5 + offset]) + pad;
    tmp[3] = (src[3 + offset] + src[4 + offset]) * 20 - (src[2 + offset] + src[5 + offset]) * 5 + (src[1 + offset] + src[6 + offset]) + pad;

    tmp += tmpStride;
    src += srcStride;
}
}
