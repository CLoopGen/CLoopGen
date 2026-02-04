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
const uint16_t *src_base = src;
int32_t *tmp_base = tmp;

for (i = 0; i < h + 5; i++) {
    ptrdiff_t idx = i * srcStride;
    ptrdiff_t tidx = i * tmpStride;
    
    // Use indirect access via base pointer and computed indices
    tmp_base[tidx + 0] = (src_base[idx + 0] + src_base[idx + 1]) * 20 
                       - (src_base[idx - 1] + src_base[idx + 2]) * 5 
                       + (src_base[idx - 2] + src_base[idx + 3]) + pad;
                       
    tmp_base[tidx + 1] = (src_base[idx + 1] + src_base[idx + 2]) * 20 
                       - (src_base[idx + 0] + src_base[idx + 3]) * 5 
                       + (src_base[idx - 1] + src_base[idx + 4]) + pad;
                       
    tmp_base[tidx + 2] = (src_base[idx + 2] + src_base[idx + 3]) * 20 
                       - (src_base[idx + 1] + src_base[idx + 4]) * 5 
                       + (src_base[idx + 0] + src_base[idx + 5]) + pad;
                       
    tmp_base[tidx + 3] = (src_base[idx + 3] + src_base[idx + 4]) * 20 
                       - (src_base[idx + 2] + src_base[idx + 5]) * 5 
                       + (src_base[idx + 1] + src_base[idx + 6]) + pad;
}
}
