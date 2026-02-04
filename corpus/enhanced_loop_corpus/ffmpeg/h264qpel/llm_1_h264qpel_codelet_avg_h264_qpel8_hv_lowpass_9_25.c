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
    for (i = 0; i < h + 5; i++) {
        int base = 0;
        tmp[base + 0] = (src[base + 0] + src[base + 1]) * 20 - (src[base - 1] + src[base + 2]) * 5 + (src[base - 2] + src[base + 3]) + pad;
        tmp[base + 1] = (src[base + 1] + src[base + 2]) * 20 - (src[base + 0] + src[base + 3]) * 5 + (src[base - 1] + src[base + 4]) + pad;
        tmp[base + 2] = (src[base + 2] + src[base + 3]) * 20 - (src[base + 1] + src[base + 4]) * 5 + (src[base + 0] + src[base + 5]) + pad;
        tmp[base + 3] = (src[base + 3] + src[base + 4]) * 20 - (src[base + 2] + src[base + 5]) * 5 + (src[base + 1] + src[base + 6]) + pad;
        tmp[base + 4] = (src[base + 4] + src[base + 5]) * 20 - (src[base + 3] + src[base + 6]) * 5 + (src[base + 2] + src[base + 7]) + pad;
        tmp[base + 5] = (src[base + 5] + src[base + 6]) * 20 - (src[base + 4] + src[base + 7]) * 5 + (src[base + 3] + src[base + 8]) + pad;
        tmp[base + 6] = (src[base + 6] + src[base + 7]) * 20 - (src[base + 5] + src[base + 8]) * 5 + (src[base + 4] + src[base + 9]) + pad;
        tmp[base + 7] = (src[base + 7] + src[base + 8]) * 20 - (src[base + 6] + src[base + 9]) * 5 + (src[base + 5] + src[base + 10]) + pad;
        tmp += tmpStride;
        src += srcStride;
    }
}
