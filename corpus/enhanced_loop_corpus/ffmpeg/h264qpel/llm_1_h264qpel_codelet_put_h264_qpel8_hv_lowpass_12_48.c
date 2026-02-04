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
    for (int outer = 0; outer < h + 5; outer++) {
        int inner_start = 0;
        int inner_end = 8;
        for (int i_inner = inner_start; i_inner < inner_end; i_inner++) {
            int idx = i_inner;
            tmp[idx] = (src[idx] + src[idx+1]) * 20 
                     - (src[idx-1] + src[idx+2]) * 5 
                     + (src[idx-2] + src[idx+3]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
