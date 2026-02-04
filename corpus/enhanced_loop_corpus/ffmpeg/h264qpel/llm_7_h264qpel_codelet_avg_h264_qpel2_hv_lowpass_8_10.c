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
    for (i = 0; i < h + 5; i++) {
        int offset = i * tmpStride;
        tmp[offset] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
        if (i > 0) {
            tmp[offset] += tmp[offset - tmpStride]; // Introduce WAW and loop-carried dependency
        }
        tmp[offset + 1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
        src += srcStride;
    }
}
