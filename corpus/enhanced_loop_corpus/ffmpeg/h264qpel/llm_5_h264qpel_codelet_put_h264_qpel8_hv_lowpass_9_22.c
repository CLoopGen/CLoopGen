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
        int offset = (i & 1) ? 4 : 0;
        if (i >= 2) {
            tmp[offset + 0] = (src[0 + offset] + src[1 + offset]) * 20 - (src[-1 + offset] + src[2 + offset]) * 5 + (src[-2 + offset] + src[3 + offset]) + pad;
            tmp[offset + 1] = (src[1 + offset] + src[2 + offset]) * 20 - (src[0 + offset] + src[3 + offset]) * 5 + (src[-1 + offset] + src[4 + offset]) + pad;
            tmp[offset + 2] = (src[2 + offset] + src[3 + offset]) * 20 - (src[1 + offset] + src[4 + offset]) * 5 + (src[0 + offset] + src[5 + offset]) + pad;
            tmp[offset + 3] = (src[3 + offset] + src[4 + offset]) * 20 - (src[2 + offset] + src[5 + offset]) * 5 + (src[1 + offset] + src[6 + offset]) + pad;
        } else {
            tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
            tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
            tmp[2] = (src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5]) + pad;
            tmp[3] = (src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
