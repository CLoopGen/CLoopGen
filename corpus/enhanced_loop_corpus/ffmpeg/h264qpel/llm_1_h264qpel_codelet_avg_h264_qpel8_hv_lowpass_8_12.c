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
    if (h + 5 > 0) {
        for (i = 0; i < h + 5; i++) {
            int j;
            for (j = 0; j < 8; j++) {
                tmp[j] = (src[j] + src[j+1]) * 20 - (src[j-1] + src[j+2]) * 5 + (src[j-2] + src[j+3]) + pad;
            }
            tmp += tmpStride;
            src += srcStride;
        }
    }
}
