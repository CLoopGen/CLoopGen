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
        int coeff = (i % 2 == 0) ? 1 : -1;
        tmp[0] = coeff * ((src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3])) + pad;
        if (i < h + 2) {
            tmp[1] = coeff * ((src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4])) + pad;
            tmp[2] = coeff * ((src[2] + src[3]) * 20 - (src[1] + src[4]) * 5 + (src[0] + src[5])) + pad;
            tmp[3] = coeff * ((src[3] + src[4]) * 20 - (src[2] + src[5]) * 5 + (src[1] + src[6])) + pad;
        } else {
            tmp[1] = tmp[2] = tmp[3] = pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
