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
    uint16_t *src_offset = src;
    int16_t *tmp_offset = tmp;
    tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
    src_offset += srcStride;
    tmp_offset += tmpStride;
    tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
    src_offset += srcStride;
    tmp_offset += tmpStride;
    tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
    src_offset += srcStride;
    tmp_offset += tmpStride;
    tmp_offset[0] = (src_offset[0] + src_offset[1]) * 20 - (src_offset[-1] + src_offset[2]) * 5 + (src_offset[-2] + src_offset[3]) + pad;
    tmp += tmpStride * 4;
    src += srcStride * 4;
    i += 3;
}
}
