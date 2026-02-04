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
    int16_t *tmp_offset = tmp;
    uint16_t *src_offset = src;
    for (int j = 0; j < 8; j++) {
        int idx = j + 2;
        tmp_offset[j] = (src_offset[j] + src_offset[j+1]) * 20 
                     - (src_offset[j-1] + src_offset[j+2]) * 5 
                     + (src_offset[j-2] + src_offset[j+3]) + pad;
    }
    tmp += tmpStride;
    src += srcStride;
}
}
