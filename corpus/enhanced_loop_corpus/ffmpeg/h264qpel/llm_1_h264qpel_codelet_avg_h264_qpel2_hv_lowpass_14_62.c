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
    for (int i1 = 0; i1 < h + 5; i1++) {
        for (int i2 = 0; i2 < 1 && i1 < h + 5; i2++) {
            tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
        }
        for (int i3 = 0; i3 < 1 && i1 < h + 5; i3++) {
            tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
