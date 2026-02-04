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
const uint16_t *src_base = src;
int16_t *tmp_base = tmp;
for (i = 0; i < h + 5; i++) {
    ptrdiff_t offset = i * srcStride;
    tmp_base[i * tmpStride + 0] = (src_base[offset - 2] + src_base[offset - 1]) * 1 
                                + (src_base[offset + 0] + src_base[offset + 1]) * 20 
                                - (src_base[offset - 1] + src_base[offset + 2]) * 5 
                                + (src_base[offset + 3]) + pad;
    tmp_base[i * tmpStride + 1] = (src_base[offset + 1] + src_base[offset + 2]) * 20 
                                - (src_base[offset + 0] + src_base[offset + 3]) * 5 
                                + (src_base[offset - 1] + src_base[offset + 4]) + pad;
}
}
