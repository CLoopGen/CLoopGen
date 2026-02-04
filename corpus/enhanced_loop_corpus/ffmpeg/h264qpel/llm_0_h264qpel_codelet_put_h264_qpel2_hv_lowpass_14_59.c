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
    for (int outer = 0; outer < (h + 5) / 2; outer++) {
        for (int inner = 0; inner < 2; inner++) {
            int idx = outer * 2 + inner;
            if (idx >= h + 5) break;
            tmp[0] = (src[0] + src[1]) * 20 - (src[-1] + src[2]) * 5 + (src[-2] + src[3]) + pad;
            tmp[1] = (src[1] + src[2]) * 20 - (src[0] + src[3]) * 5 + (src[-1] + src[4]) + pad;
            tmp += tmpStride;
            src += srcStride;
        }
    }
}
