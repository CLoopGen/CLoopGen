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
const int16_t *base_tmp = tmp;
const uint16_t *base_src = src;
for (i = 0; i < h + 5; i++) {
    int idx = i * tmpStride;
    int sidx = i * srcStride;
    
    ((int16_t*)base_tmp)[idx + 0] = (base_src[sidx + 0] + base_src[sidx + 1]) * 20 - 
                                   (base_src[sidx - 1] + base_src[sidx + 2]) * 5 + 
                                   (base_src[sidx - 2] + base_src[sidx + 3]) + pad;
    ((int16_t*)base_tmp)[idx + 1] = (base_src[sidx + 1] + base_src[sidx + 2]) * 20 - 
                                   (base_src[sidx + 0] + base_src[sidx + 3]) * 5 + 
                                   (base_src[sidx - 1] + base_src[sidx + 4]) + pad;
    ((int16_t*)base_tmp)[idx + 2] = (base_src[sidx + 2] + base_src[sidx + 3]) * 20 - 
                                   (base_src[sidx + 1] + base_src[sidx + 4]) * 5 + 
                                   (base_src[sidx + 0] + base_src[sidx + 5]) + pad;
    ((int16_t*)base_tmp)[idx + 3] = (base_src[sidx + 3] + base_src[sidx + 4]) * 20 - 
                                   (base_src[sidx + 2] + base_src[sidx + 5]) * 5 + 
                                   (base_src[sidx + 1] + base_src[sidx + 6]) + pad;
}
}
