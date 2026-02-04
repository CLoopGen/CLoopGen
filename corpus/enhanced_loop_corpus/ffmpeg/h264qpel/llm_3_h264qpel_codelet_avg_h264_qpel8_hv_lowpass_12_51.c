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
        int offset = 0;
        for (int j = 0; j < 8; j++) {
            int src_center = j + 0;
            tmp[j] = (src[src_center] + src[src_center + 1]) * 20
                   - (src[src_center - 1] + src[src_center + 2]) * 5
                   + (src[src_center - 2] + src[src_center + 3]) + pad;
        }
        tmp += tmpStride;
        src += srcStride;
    }
}
