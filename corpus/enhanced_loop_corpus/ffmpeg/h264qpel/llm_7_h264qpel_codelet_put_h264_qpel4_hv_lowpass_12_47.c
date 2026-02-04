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
        int32_t val = (src[0] + src[1] + src[2] + src[3]) * 10 + pad;
        tmp[0] = val;
        tmp[1] = val;
        tmp[2] = val;
        tmp[3] = val;
        tmp += tmpStride;
        src += srcStride;
    }
}
