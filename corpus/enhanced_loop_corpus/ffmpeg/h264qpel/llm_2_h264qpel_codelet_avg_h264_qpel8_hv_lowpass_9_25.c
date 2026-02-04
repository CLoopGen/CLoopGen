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
    int offset = i * tmpStride;
    int src_offset = i * srcStride;
    tmp[offset + 0] = (src[src_offset + 0] + src[src_offset + 1]) * 20 - 
                      (src[src_offset - 1] + src[src_offset + 2]) * 5 + 
                      (src[src_offset - 2] + src[src_offset + 3]) + pad;
    tmp[offset + 1] = (src[src_offset + 1] + src[src_offset + 2]) * 20 - 
                      (src[src_offset + 0] + src[src_offset + 3]) * 5 + 
                      (src[src_offset - 1] + src[src_offset + 4]) + pad;
    tmp[offset + 2] = (src[src_offset + 2] + src[src_offset + 3]) * 20 - 
                      (src[src_offset + 1] + src[src_offset + 4]) * 5 + 
                      (src[src_offset + 0] + src[src_offset + 5]) + pad;
    tmp[offset + 3] = (src[src_offset + 3] + src[src_offset + 4]) * 20 - 
                      (src[src_offset + 2] + src[src_offset + 5]) * 5 + 
                      (src[src_offset + 1] + src[src_offset + 6]) + pad;
    tmp[offset + 4] = (src[src_offset + 4] + src[src_offset + 5]) * 20 - 
                      (src[src_offset + 3] + src[src_offset + 6]) * 5 + 
                      (src[src_offset + 2] + src[src_offset + 7]) + pad;
    tmp[offset + 5] = (src[src_offset + 5] + src[src_offset + 6]) * 20 - 
                      (src[src_offset + 4] + src[src_offset + 7]) * 5 + 
                      (src[src_offset + 3] + src[src_offset + 8]) + pad;
    tmp[offset + 6] = (src[src_offset + 6] + src[src_offset + 7]) * 20 - 
                      (src[src_offset + 5] + src[src_offset + 8]) * 5 + 
                      (src[src_offset + 4] + src[src_offset + 9]) + pad;
    tmp[offset + 7] = (src[src_offset + 7] + src[src_offset + 8]) * 20 - 
                      (src[src_offset + 6] + src[src_offset + 9]) * 5 + 
                      (src[src_offset + 5] + src[src_offset + 10]) + pad;
}
}
