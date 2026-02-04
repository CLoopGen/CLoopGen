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
    for (int outer = 0; outer < h + 5; outer++) {
        for (int inner = 0; inner < 8; inner++) {
            int offset = inner;
            tmp[offset] = (src[offset] + src[offset + 1]) * 20 
                        - (src[offset - 1] + src[offset + 2]) * 5 
                        + (src[offset - 2] + src[offset + 3]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
