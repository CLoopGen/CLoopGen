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
        int16_t *tmp_offset = tmp + i * tmpStride;
        const uint8_t *src_offset = src + i * srcStride;
        
        tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
        tmp_offset[1] = (src_offset[1] + src_offset[2]) * 20 - (src_offset[0] + src_offset[3]) * 5 + (src_offset[-1] + src_offset[4]) + pad;
    }
}
